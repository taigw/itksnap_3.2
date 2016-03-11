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
#include "SnakeWizardModel.h"

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
    m_Model = model->GetSnakeWizardModel();
}

void TRGPanel::Initialize()
{
    m_Model->OnTRGModeEnter();
}

void TRGPanel::on_btnSetThreshold_clicked()
{
    
}
void TRGPanel::on_btnAddSeeds_clicked()
{
    
}
void TRGPanel::on_btnUpdate_clicked()
{
    m_Model->OnTRGFinish();
    emit sgl_TRGFinished();
}
void TRGPanel::on_btnCancel_clicked()
{
   
    // Tell the model to return to initialization state
    m_Model->OnCancelSegmentation();
    emit sgl_TRGFinished();
}
