/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Column.h
 * Author: max
 *
 * Created on 14 июля 2016 г., 11:56
 */
#ifndef COLUMN_H
#define COLUMN_H

#include <string>

namespace DBoW2 {
 
using namespace std;
    
class Column {
public:
    Column();
    virtual ~Column();
    
    static const string NAME;
    static const string BRANCHING;
    static const string DEPTH;
    static const string SCORING_TYPE;
    static const string WEIGHTING_TYPE;
    
    static const string ID;
    static const string PARENT_ID;
    static const string WEIGHT;
    static const string DESCRIPTOR;
    static const string VOCAB_NAME;
    
    static const string NODE_ID;
    
    
    static const string ENTRIES_NUM;
    static const string USING_DI;
    static const string DI_LEVELS;
    
    static const string IMG_ID;
    static const string IMG_NAME;
    static const string DATASET_NAME;
    
private:

};

}
#endif /* COLUMN_H */

