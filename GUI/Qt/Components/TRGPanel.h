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
signals:
    void sgl_TRGFinished();
private slots:
    void on_btnSetThreshold_clicked();
    void on_btnAddSeeds_clicked();
    void on_btnUpdate_clicked();
    void on_btnCancel_clicked();
private:
    Ui::TRGPanel *ui;
    
    GlobalUIModel *m_ParentModel;
};
#endif // TRGPANEL_H
