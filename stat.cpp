
#include "stat.h"
#include "ui_stat.h"
#include <QPainter>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QHeaderView>

StatDialog::StatDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StatDialog)
{
    ui->setupUi(this);
    setWindowTitle("Statistiques des Notes");

    ui->chartTypeComboBox->addItem("Graphique à barres");
    ui->chartTypeComboBox->addItem("Graphique circulaire");

    connect(ui->chartTypeComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onChartTypeChanged(int)));

    setupCharts();
    updateStatistics();
}

StatDialog::~StatDialog()
{
    delete ui;
}

void StatDialog::setupCharts()
{
    gradeChart = new QChart();
    gradeChart->setTitle("Répartition des Notes");
    gradeChart->setTheme(QChart::ChartThemeLight);
    gradeChart->setAnimationOptions(QChart::AllAnimations);

    ui->chartView->setChart(gradeChart);
    ui->chartView->setRenderHint(QPainter::Antialiasing);

    setupBarChart();
}

void StatDialog::setupBarChart()
{
    gradeChart->removeAllSeries();
    gradeSeries = new QBarSeries();

    QBarSet *refuseSet = new QBarSet("Refusé (<8)");
    QBarSet *controleSet = new QBarSet("Controle (8-9.99)");
    QBarSet *admisSet = new QBarSet("Admis (≥10)");

    refuseSet->setColor(QColor(255, 99, 71));
    controleSet->setColor(QColor(255, 165, 0));
    admisSet->setColor(QColor(60, 179, 113));

    gradeSeries->append(refuseSet);
    gradeSeries->append(controleSet);
    gradeSeries->append(admisSet);

    gradeChart->addSeries(gradeSeries);

    QStringList categories;
    categories << "Notes";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    gradeChart->addAxis(axisX, Qt::AlignBottom);
    gradeSeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, 10);
    axisY->setLabelFormat("%d");
    gradeChart->addAxis(axisY, Qt::AlignLeft);
    gradeSeries->attachAxis(axisY);

    gradeChart->legend()->setVisible(true);
    gradeChart->legend()->setAlignment(Qt::AlignBottom);
}

void StatDialog::setupPieChart()
{
    gradeChart->removeAllSeries();
    gradePieSeries = new QPieSeries();
    gradeChart->addSeries(gradePieSeries);
    gradeChart->legend()->setVisible(true);
    gradeChart->legend()->setAlignment(Qt::AlignRight);

    foreach(QAbstractAxis *axis, gradeChart->axes()) {
        gradeChart->removeAxis(axis);
    }
}

void StatDialog::onChartTypeChanged(int index)
{
    if (index == 0) {
        setupBarChart();
    } else {
        setupPieChart();
    }

    updateStatistics();
}

QMap<QString, int> StatDialog::getStatistiques()
{
    QMap<QString, int> stats;
    QSqlQuery query;

    query.prepare("SELECT "
                  "COUNT(CASE WHEN NOTE < 8 THEN 1 END) as refuse, "
                  "COUNT(CASE WHEN NOTE >= 8 AND NOTE < 10 THEN 1 END) as controle, "
                  "COUNT(CASE WHEN NOTE >= 10 THEN 1 END) as admis, "
                  "COUNT(*) as total "
                  "FROM RESULTAT");

    if (query.exec() && query.next()) {
        stats["refuse"] = query.value("refuse").toInt();
        stats["controle"] = query.value("controle").toInt();
        stats["admis"] = query.value("admis").toInt();
        stats["total"] = query.value("total").toInt();
    } else {
        qDebug() << "Erreur lors du calcul des statistiques:" << query.lastError().text();
    }

    return stats;
}

QTableWidget* StatDialog::createStatsTable(QWidget* parent)
{
    QTableWidget* statsTable = new QTableWidget(3, 2, parent);
    statsTable->setHorizontalHeaderLabels(QStringList() << "Catégorie" << "Nombre d'étudiants");

    QTableWidgetItem *refuseItem = new QTableWidgetItem("Refusé (<8)");
    refuseItem->setBackground(QColor(255, 99, 71));
    statsTable->setItem(0, 0, refuseItem);

    QTableWidgetItem *controleItem = new QTableWidgetItem("Contrôle (8-9.99)");
    controleItem->setBackground(QColor(255, 165, 0));
    statsTable->setItem(1, 0, controleItem);

    QTableWidgetItem *admisItem = new QTableWidgetItem("Admis (≥10)");
    admisItem->setBackground(QColor(60, 179, 113));
    statsTable->setItem(2, 0, admisItem);

    QMap<QString, int> stats = getStatistiques();

    statsTable->setItem(0, 1, new QTableWidgetItem(QString::number(stats["refuse"])));
    statsTable->setItem(1, 1, new QTableWidgetItem(QString::number(stats["controle"])));
    statsTable->setItem(2, 1, new QTableWidgetItem(QString::number(stats["admis"])));

    statsTable->setStyleSheet(
        "QTableWidget {"
        "    border: 1px solid #0078D7;"
        "    border-radius: 5px;"
        "    background-color: white;"
        "    gridline-color: #E1E1E1;"
        "}"
        "QTableWidget::item {"
        "    padding: 5px;"
        "}"
        "QHeaderView::section {"
        "    background-color: #0078D7;"
        "    color: white;"
        "    padding: 5px;"
        "    border: none;"
        "}"
        );

    statsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    statsTable->verticalHeader()->setVisible(false);
    statsTable->setEditTriggers(QTableWidget::NoEditTriggers);
    statsTable->setFixedHeight(150);

    return statsTable;
}

void StatDialog::updateStatistics()
{
    QMap<QString, int> stats = getStatistiques();

    if (ui->chartTypeComboBox->currentIndex() == 0) {
        QBarSet *refuseSet = gradeSeries->barSets().at(0);
        QBarSet *controleSet = gradeSeries->barSets().at(1);
        QBarSet *admisSet = gradeSeries->barSets().at(2);

        refuseSet->remove(0, refuseSet->count());
        controleSet->remove(0, controleSet->count());
        admisSet->remove(0, admisSet->count());

        *refuseSet << stats["refuse"];
        *controleSet << stats["controle"];
        *admisSet << stats["admis"];

        int maxCount = qMax(qMax(stats["refuse"], stats["controle"]), stats["admis"]);
        QValueAxis *axisY = qobject_cast<QValueAxis*>(gradeChart->axes(Qt::Vertical).first());
        if (axisY) {
            axisY->setRange(0, maxCount + 1);
        }
    } else {
        gradePieSeries->clear();

        gradePieSeries->append("Refusé (<8)", stats["refuse"]);
        gradePieSeries->append("Controle (8-9.99)", stats["controle"]);
        gradePieSeries->append("Admis (≥10)", stats["admis"]);

        if (gradePieSeries->slices().size() >= 3) {
            int total = stats["refuse"] + stats["controle"] + stats["admis"];

            QPieSlice *refuseSlice = gradePieSeries->slices().at(0);
            QPieSlice *controleSlice = gradePieSeries->slices().at(1);
            QPieSlice *admisSlice = gradePieSeries->slices().at(2);

            refuseSlice->setColor(QColor(255, 99, 71));
            controleSlice->setColor(QColor(255, 165, 0));
            admisSlice->setColor(QColor(60, 179, 113));

            if (total > 0) {
                refuseSlice->setLabel(QString("Refusé:%1%").arg((stats["refuse"] * 100.0) / total, 0, 'f', 1));
                controleSlice->setLabel(QString("Contrôle :%1%").arg((stats["controle"] * 100.0) / total, 0, 'f', 1));
                admisSlice->setLabel(QString("Admis (≥10): %1%").arg((stats["admis"] * 100.0) / total, 0, 'f', 1));
            }

            refuseSlice->setExploded();
            refuseSlice->setLabelVisible();
            controleSlice->setLabelVisible();
            admisSlice->setLabelVisible();
        }
    }
}
