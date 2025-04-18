#ifndef TRANSPORT_H
#define TRANSPORT_H
#include <QCalendarWidget>
#include <QDate>
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QTableWidget>


#include <QQuickWidget>
#include <QVariantList>
#include <QVariantMap>
namespace Ui {
class transport;  // Nom en minuscule
}

class transport : public QDialog
{
    Q_OBJECT
    Q_PROPERTY(QVariantList markersToAdd READ markersToAdd NOTIFY markersChanged)


public:
    explicit transport(QWidget *parent = nullptr);
    ~transport();

    QVariantList markersToAdd() const;
    void addMarker(double lat, double lng, const QString &destination);
    void addMarkerToMap(double lat, double lng, const QString &destination);

signals:
    void markersChanged();
    void mapClicked(double lat, double lng);

public slots:
    void onMapClicked(double lat, double lng);
    void onMarkerAdded(double lat, double lng);

private slots:
    void on_recherche_clicked();  // Slot pour la recherche

    void on_ajouter_clicked();

    void on_tableWidgetlivraison_itemClicked(QTableWidgetItem *item);

    void on_modifier_clicked();

    void on_supprimer_clicked();

    void on_annuler_clicked();
    void on_calendarLivraison_clicked(const QDate &date);
    void on_comboLivreurs_currentIndexChanged(int index);

    void on_pdf_2_clicked();


    void on_statistique_clicked();

    void on_tri_clicked();

private:
    Ui::transport *ui;
    void afficherTransports();  // Méthode pour afficher les données
    QQuickWidget *m_quickWidget;
    QVariantList m_markers;
    void chargerLivreurs();
    void afficherLivraisonsParDate(const QDate &date, const QString &livreur);
    void initMap();
    void handleQmlStatusChanged(QQuickWidget::Status status);
    void loadAllMarkers();
    void clearMarkers();
    void colorierDatesLivraison();
    void generatePdfForTransport(const QString& codeBox);

};

#endif // TRANSPORT_H
