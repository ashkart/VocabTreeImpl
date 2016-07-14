/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Column.h"

namespace DBoW2 {

    using namespace std;
    Column::Column() {}

    Column::~Column(){}
    
    const string Column::ID = "ID";
    const string Column::BRANCHING = "BRANCHING";
    const string Column::DEPTH = "DEPTH";
    const string Column::NAME = "NAME";
    const string Column::SCORING_TYPE = "SCORING_TYPE";
    const string Column::WEIGHTING_TYPE = "WEIGHTING_TYPE";
    const string Column::PARENT_ID = "PARENT_ID";
    const string Column::WEIGHT = "WEIGHT";
    const string Column::DESCRIPTOR = "DESCRIPTOR";
    const string Column::VOCAB_NAME = "VOCAB_NAME";
    const string Column::NODE_ID = "NODE_ID";
    const string Column::ENTRIES_NUM = "ENTRIES_NUM";
    const string Column::USING_DI = "USING_DI";
    const string Column::DI_LEVELS = "DI_LEVELS";
    const string Column::IMG_ID = "IMG_ID";
    const string Column::IMG_NAME = "IMG_NAME";
    const string Column::DATASET_NAME = "DATASET_NAME";
}