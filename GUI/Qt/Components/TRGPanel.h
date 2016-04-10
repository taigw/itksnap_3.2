#ifndef TRGPANEL_H
#define TRGPANEL_H

#include <QWidget>

namespace Ui {
    class TRGPanel;
}

class GlobalUIModel;
class SnakeWizardModel;

class TRGPanel: public QWidget
{
    Q_OBJECT
    
public:
    explicit TRGPanel(QWidget *parent=0);
    ~TRGPanel();
    
    void SetModel(GlobalUIModel *model);
    void Initialize();
signals:
    void sgl_TRGFinished();
private slots:
    void on_btnSetThreshold_clicked();
    void on_btnStartGrow_clicked();
    void on_btnFinish_clicked();
    void on_btnCancel_clicked();
private:
    Ui::TRGPanel *ui;
    
    GlobalUIModel *m_ParentModel;
    SnakeWizardModel *m_Model;
    
    bool seedExist;// indicated whether seeds have been added 
};
#endif // TRGPANEL_H
