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

void changeStructure(const vector<float> &plain, vector<vector<float> > &out,
  int L);

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
    string imageDir = "images";
    
    
    try {
        string conn_str = "host=localhost user=admin password=ss dbname=pgTest";
        connection c(conn_str);

        //cout << "Retrieving voc_tree..." << endl;
        const int k = 8;
        const int L = 6;
        const WeightingType weight = TF_IDF;
        const ScoringType score = L1_NORM;
        const string vocabularyName = "myVocabulary";
        
        Surf64Vocabulary voc(vocabularyName, k, L, weight, score);
        getFeatures(features, imageDir);
        voc.create(features);
        voc.saveToPG(c);
        
        cout << "Creating database..." << endl;
        Surf64Database db(c, vocabularyName);// можно использовать экземпляр voc,
                                             // вызвав конструктор "полегче",
                                             // но для демонстрации работы с СУБД 
                                             // оставляю так
        /*================================================================*/
        cout << "loading data into db..." << endl;
        loadFeaturesToDB(features, imageDir, db);
        
        const string datasetName = "myImageDataset";
        db.saveToPG(c, datasetName);
        cout << "DB writed!" << endl; 
        
        //теперь попробуем выполнить запрос 
        
        cout << "Querying result..." << endl;
        QueryResults ret;
        features.clear();
        features.reserve(1);
        string qi = "/home/max/NetBeansProjects/CppApplication_1/im2/255-srbn.jpg";
        getFeature(features, qi);
        db.query(features[0], ret, 4);
        
        cout << "the result is:\n" << ret << endl;
        
        /**
         * как видно, запросы сейчас выполняются к набору данных, загруженному 
         * в память из БД а не к самой БД.
         * 
         */
        
    } catch (const pqxx::pqxx_exception &e) {
        std::cerr << "Error:\n" << e.base().what() << std::endl;
    }
    cv::waitKey();
    return 0;
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