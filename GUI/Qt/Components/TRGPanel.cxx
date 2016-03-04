//
//  TRGPanel.cpp
//  
//
//  Created by Guotai Wang on 04/03/2016.
//
//

#include "TRGPanel.h"
#include "ui_TRGPanel.h"
#include "GlobalUIModel.h"

TRGPanel::TRGPanel(QWidget *parent):
    QWidget(parent),
    ui(new Ui::TRGPanel)
{
    ui->setupUi(this);
    
}

TRGPanel::~TRGPanel()
{
    delete ui;
}

void TRGPanel::SetModel(GlobalUIModel *model)
{
    m_ParentModel=model;
}

void TRGPanel::Initialize()
{
    
}

void TRGPanel::slt_btnSetThreshold_clicked()
{
    
}
void TRGPanel::slt_btnAddSeeds_clicked()
{
    
}
void TRGPanel::slt_btnUpdate_clicked()
{
    
}
void TRGPanel::slt_btnCancelSegmentation_clicked()
{
    
}
