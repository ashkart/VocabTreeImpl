/**
 * File: Demo.cpp
 * Date: November 2011
 * Author: Dorian Galvez-Lopez
 * Description: demo application of DBoW2
 * License: see the LICENSE.txt file
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <sys/types.h>
#include <dirent.h>

// DBoW2
#include "DBoW2.h" // defines Surf64Vocabulary and Surf64Database

#include "DUtils.h"
#include "DUtilsCV.h" // defines macros CVXX
#include "DVision.h"

#include "pqxx/connection"
#include "pqxx/transaction"

// OpenCV
#include <opencv/cv.h>
#include <opencv/highgui.h>
#if CV24
#include <opencv2/nonfree/features2d.hpp>
#endif

using namespace DBoW2;
using namespace DUtils;
using namespace std;
using namespace pqxx;


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void loadFeatures(vector<vector<vector<float> > > &features);
void changeStructure(const vector<float> &plain, vector<vector<float> > &out,
  int L);
void testVocCreation(const vector<vector<vector<float> > > &features);
void testDatabase(const vector<vector<vector<float> > > &features);


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// number of training images
const int NIMAGES = 6;

// extended surf gives 128-dimensional vectors
const bool EXTENDED_SURF = false;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void wait()
{
  cout << endl << "Press enter to continue" << endl;
  getchar();
}

// ----------------------------------------------------------------------------

void getFeature(vector<vector<vector<float> > > &features, string &imageDir)
{
    cv::SURF surf(400, 4, 2, EXTENDED_SURF);
    vector<cv::KeyPoint> keypoints;
    vector<float> descriptors;
    cv::Mat image = cv::imread(imageDir, 0);
    cv::Mat mask;
    surf(image, mask, keypoints, descriptors);
    features.push_back(vector<vector<float> >());
    changeStructure(descriptors, features.back(), surf.descriptorSize());
}

void getFeatures(vector<vector<vector<float> > > &features, string &imageDir)
{
    cv::SURF surf(400, 4, 2, EXTENDED_SURF);
    
    features.clear();
    features.reserve(NIMAGES);

    DIR *dir = opendir(imageDir.c_str());
    if(dir)
    {
        struct dirent *ent;
        while((ent = readdir(dir)) != NULL)
        {
            char *dname = ent->d_name;
            string path = imageDir + "/";
            path = path + dname;
            if (sizeof(dname) > 2 && dname[0] != '.')
            {
                cout << "Extracting SURF features of " << dname << endl;
                getFeature(features, path);
            }
        }
    }
    
}

void loadFeaturesToDB(vector<vector<vector<float> > > &features, string &imageDir, Surf64Database &db)
{
    cv::SURF surf(400, 4, 2, EXTENDED_SURF);
    
    features.clear();
    features.reserve(NIMAGES);

    DIR *dir = opendir(imageDir.c_str());
    if(dir)
    {
        struct dirent *ent;
        while((ent = readdir(dir)) != NULL)
        {
            char *dname = ent->d_name;
            string path = imageDir + "/";
            path = path + dname;
            if (sizeof(dname) > 2 && dname[0] != '.')
            {
                cout << "Processsing image " << dname << endl;
                getFeature(features, path);
                db.add(features.back(), dname);
            }
        }
    }
}

int main()
{
    vector<vector<vector<float> > > features;
    string fileDB = "test_db.yml.gz";
    string fileVoc = "small_voc.yml.gz";
    string imageDir = "/home/max/NetBeansProjects/CppApplication_1/im2";
    
  
    try {
        string conn_str = "host=localhost user=admin password=ss dbname=pgTest";
        connection c(conn_str);
        
        
        //cout << "Retrieving voc_tree..." << endl;
        const int k = 8;
        const int L = 6;
        const WeightingType weight = TF_IDF;
        const ScoringType score = L1_NORM;
        const string tname = "testTree";
        
        Surf64Vocabulary voc(c,tname);
        
        cout << "Creating database..." << endl;
        Surf64Database db("test_db.yml.gz");
        
        cout << "loading data into db..." << endl;
        loadFeaturesToDB(features, imageDir, db);
        
        db.save(fileDB);
        cout << "Job Done!" << endl; 
        
        //wait();
        
        /*
        cout << "Querying result..." << endl;
        QueryResults ret;
        features.clear();
        features.reserve(1);
        string qi = "/home/max/NetBeansProjects/CppApplication_1/im2/255-srbn.jpg";
        getFeature(features, qi);
        db.query(features[0], ret, 4);

        cout << "the result is:\n" << ret << endl;
        */
    } catch (const pqxx::pqxx_exception &e) {
        std::cerr << "Error:\n" << e.base().what() << std::endl;
    }

    


    cv::waitKey();
    return 0;
}

// ----------------------------------------------------------------------------

void loadFeatures(vector<vector<vector<float> > > &features)
{
    bool isCanLoad = false;
    features.clear();
    features.reserve(NIMAGES);

    cv::SURF surf(400, 4, 2, EXTENDED_SURF);

    cout << "Extracting SURF features..." << endl;

    DIR *dir = opendir("images");
    if(dir)
    {
        struct dirent *ent;
        while((ent = readdir(dir)) != NULL)
        {
            char *dname = ent->d_name;
            if (sizeof(dname) > 2 && dname[0] != '.')
            {
                stringstream ss;
                ss << "images" << "/" << dname;
                //puts(ent->d_name); //вывод имени элемента папки *dir
                cout << ss.str() << endl;
                vector<cv::KeyPoint> keypoints;
                vector<float> descriptors;
                stringstream fld;
                fld << "surf/" << dname << ".yml";
                if (isCanLoad)
                {
                    cv::FileStorage fs(fld.str(), cv::FileStorage::READ);
                    //cv::FileNode kptFileNode = fs["Keypoints"];
                    //read(kptFileNode, keypoints);
                    fs["Descriptors"] >> descriptors;
                    //fs["Name"] >> dname;
                    fs.release();
                }
                else
                {
                    cv::Mat image = cv::imread(ss.str(), 0);
                    cv::Mat mask;
                    surf(image, mask, keypoints, descriptors);
                    cv::FileStorage fs(fld.str(), cv::FileStorage::WRITE);
                    //cv::write(fs, "Keypoints", keypoints);
                    cv::write(fs, "Descriptors", descriptors);
                    cv::write(fs, "Name", dname);
                    fs.release();
                }
                features.push_back(vector<vector<float> >());
                changeStructure(descriptors, features.back(), surf.descriptorSize());
            }
        }
    }
    else
    {
        fprintf(stderr, "Error opening directory\n");
    }
}

// ----------------------------------------------------------------------------

void changeStructure(const vector<float> &plain, vector<vector<float> > &out,
  int L)
{
  out.resize(plain.size() / L);

  unsigned int j = 0;
  for(unsigned int i = 0; i < plain.size(); i += L, ++j)
  {
    out[j].resize(L);
    std::copy(plain.begin() + i, plain.begin() + i + L, out[j].begin());
  }
}

// ----------------------------------------------------------------------------