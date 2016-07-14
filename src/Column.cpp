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
    
    const string Column::ID = "id";
    const string Column::BRANCHING = "branching";
    const string Column::DEPTH = "depth";
    const string Column::NAME = "name";
    const string Column::SCORING_TYPE = "scoring_type";
    const string Column::WEIGHTING_TYPE = "weighting_type";
    const string Column::PARENT_ID = "parent_id";
    const string Column::WEIGHT = "weight";
    const string Column::DESCRIPTOR = "descriptor";
    const string Column::VOCAB_NAME = "vocab_name";
    const string Column::NODE_ID = "node_id";
    const string Column::ENTRIES_NUM = "entries_num";
    const string Column::USING_DI = "using_di";
    const string Column::DI_LEVELS = "di_levels";
    const string Column::IMG_ID = "img_id";
    const string Column::IMG_NAME = "img_name";
    const string Column::DATASET_NAME = "dataset_name";
}