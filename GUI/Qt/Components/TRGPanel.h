#ifndef TRGPANEL_H
#define TRGPANEL_H

#include <QWidget>

namespace Ui {
    class TRGPanel;
}

class GlobalUIModel;

class TRGPanel: public QWidget
{
    Q_OBJECT
    
public:
    explicit TRGPanel(QWidget *parent=0);
    ~TRGPanel();
    
    void SetModel(GlobalUIModel *model);
    void Initialize();
private slots:
    void slt_btnSetThreshold_clicked();
    void slt_btnAddSeeds_clicked();
    void slt_btnUpdate_clicked();
    void slt_btnCancelSegmentation_clicked();
private:
    Ui::TRGPanel *ui;
    
    GlobalUIModel *m_ParentModel;
};
#endif // TRGPANEL_H
