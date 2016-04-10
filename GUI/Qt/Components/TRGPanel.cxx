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
#include "QtToolbarCoupling.h"
#include "QtSliderCoupling.h"
#include "QtDoubleSpinBoxCoupling.h"
#include "QtRadioButtonCoupling.h"
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
    
    // Couple the thresholding controls
    makeCoupling(ui->inThreshLowerSlider, m_Model->GetThresholdLowerModel());
    makeCoupling(ui->inThreshLowerSpin, m_Model->GetThresholdLowerModel());
    makeCoupling(ui->inThreshUpperSlider, m_Model->GetThresholdUpperModel());
    makeCoupling(ui->inThreshUpperSpin, m_Model->GetThresholdUpperModel());
    makeRadioGroupCoupling(ui->grpThreshMode, m_Model->GetThresholdModeModel());
    
    // Activation of thresholding controls
    activateOnFlag(ui->inThreshLowerSlider, m_Model, SnakeWizardModel::UIF_LOWER_THRESHOLD_ENABLED);
    activateOnFlag(ui->inThreshLowerSpin, m_Model, SnakeWizardModel::UIF_LOWER_THRESHOLD_ENABLED);
    activateOnFlag(ui->inThreshUpperSlider, m_Model, SnakeWizardModel::UIF_UPPER_THRESHOLD_ENABLED);
    activateOnFlag(ui->inThreshUpperSpin, m_Model, SnakeWizardModel::UIF_UPPER_THRESHOLD_ENABLED);
 
    ui->labelSeedTips->setVisible(false);
    seedExist=false;
}

void TRGPanel::Initialize()
{
    m_Model->OnTRGModeEnter();
}

void TRGPanel::on_btnSetThreshold_clicked()
{
    
}
void TRGPanel::on_btnStartGrow_clicked()
{
    m_Model->OnTRGUpdate();
}
void TRGPanel::on_btnFinish_clicked()
{
//    m_Model->OnTRGUpdate();
    m_Model->OnTRGFinish();
//    emit sgl_TRGFinished();
}
void TRGPanel::on_btnCancel_clicked()
{
   
    // Tell the model to return to initialization state
    m_Model->OnCancelSegmentation();
    emit sgl_TRGFinished();
}
