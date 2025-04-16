#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "email.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
    connect(ui->afficher, &QPushButton::clicked, this, &MainWindow::on_afficher_clicked);
    connect(ui->supp, &QPushButton::clicked, this, &MainWindow::on_supp_clicked);
    connect(ui->modifier, &QPushButton::clicked, this, &MainWindow::on_modifier_clicked);
    connect(ui->rechercher, &QPushButton::clicked, this, &MainWindow::on_rechercher_clicked);
    connect(ui->pushButton_send_2, &QPushButton::clicked, this, &MainWindow::on_pushButton_send_2_clicked);
    connect(ui->pushButton_delete, &QPushButton::clicked, this, &MainWindow::on_pushButton_delete_clicked);
    connect(ui->pb_stat, &QPushButton::clicked, this, &MainWindow::on_pb_stat_clicked);


    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::on_pushButton_2_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::on_pb_PDF_clicked);

    // Base de connaissances du chatbot
    knowledgeBase["Bonjour"] = "Bonjour ! Comment puis-je vous aider ?";
    knowledgeBase["Quels sont les horaires de travail ?"] = "Les horaires de travail sont de 8h à 17h du lundi au vendredi.";
    knowledgeBase["Comment poser une demande de congé ?"] = "Vous devez remplir le formulaire de demande de congé et l'envoyer au responsable des ressources humaines.";
    knowledgeBase["Où se trouve le service informatique ?"] = "Le service informatique se trouve au deuxième étage, à côté de la salle de réunion.";


    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS messages ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP, "
               "sender TEXT, "
               "message TEXT)");

    // Initialisation du timer pour charger les messages toutes les 2 secondes
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::loadMessages);
    timer->start(2000); // Actualise toutes les 2 secondes

    // Chargement initial des messages
    loadMessages();


}

MainWindow::~MainWindow()
{
    delete ui;

}
void MainWindow::on_pushButton_clicked()
{
    QString id_employe=ui->lineEdit_2->text();
    QString nom=ui->lineEdit_6->text();
    QString prenom=ui->lineEdit_5->text();
    int tel=ui->lineEdit_4->text().toInt();
    int salaire=ui->lineEdit_3->text().toInt();
    QString genre=ui->lineEdit->text();
    QString adresseemploye=ui->lineEdit_8->text();
    QString presence=ui->comboBox_3->currentText();
    QString spec=ui->lineEdit_9->text();
    employe n(id_employe,nom,prenom,tel,salaire,genre,adresseemploye,presence,spec);

    bool test=n.ajouter();
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),QObject::tr("ajout effectué"),QMessageBox::Cancel);
        ui->tableView->setModel(temploye.afficher());
        ui->lineEdit_2->clear();
        ui->lineEdit_6->clear();
        ui->lineEdit_5->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit->clear();
        ui->lineEdit_8->clear();
        ui->comboBox_3->setCurrentIndex(-1);
        ui->lineEdit_9->clear();
    }

}
void MainWindow::on_afficher_clicked()
{

    ui->tableView->setModel(temploye.afficher());//refresh
}


void MainWindow::on_supp_clicked()
{
    QString id_employe =ui->lineEdit_7->text();
    QMessageBox msgbox;
    msgbox.setWindowTitle("supprimer");
    msgbox.setText("voulez_vous supprimer ce client?");
    msgbox.setStandardButtons(QMessageBox ::Yes);
    msgbox.addButton(QMessageBox::No);
    if(msgbox.exec()==QMessageBox::Yes)

    {
        bool test=temploye.supprimer(id_employe);

        if(test)
        {
            ui->tableView->setModel(temploye.afficher());
            ui->lineEdit_7->clear();
        }
        else
        {

            QMessageBox ::critical(nullptr,QObject::tr("supprimer un client"),
                                   QObject::tr("Erreur.\n"
                                               "click cancel to exit"),QMessageBox::Cancel);
        }
    }
    else
        ui->tableView->setModel(temploye.afficher());

}


void MainWindow::on_modifier_clicked()
{
    QString id_employe = ui->lineEdit_17->text();
    QString nom = ui->lineEdit_16->text();
    QString prenom = ui->lineEdit_15->text();
    int tel = ui->lineEdit_13->text().toInt();
    int salaire = ui->lineEdit_18->text().toInt();
    QString genre = ui->lineEdit_11->text();
    QString adresseemploye = ui->lineEdit_12->text();
    QString presence = ui->comboBox_4->currentText();
    QString specialite = ui->lineEdit_14->text();

    // Check if ID is provided, since it's necessary for modification
    if (id_employe.isEmpty()) {
        QMessageBox::information(nullptr, QObject::tr("No ID Entered"),
                                 QObject::tr("Please enter an ID to modify."), QMessageBox::Ok);
        return;
    }

    bool test = temploye.modifier(id_employe, nom, prenom, tel, salaire, genre, adresseemploye, presence, specialite);

    if (test) {
        ui->tableView->setModel(temploye.afficher()); // Refresh view
        // Clear input fields
        ui->lineEdit_17->clear();
        ui->lineEdit_16->clear();
        ui->lineEdit_15->clear();
        ui->lineEdit_13->clear();
        ui->lineEdit_18->clear();
        ui->lineEdit_11->clear();
        ui->lineEdit_12->clear();
        ui->comboBox_4->setCurrentIndex(-1);
        ui->lineEdit_14->clear();

        QMessageBox::information(nullptr, QObject::tr("Modifier un client"),
                                 QObject::tr("Modification réussie."), QMessageBox::Ok);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un client"),
                              QObject::tr("Erreur lors de la modification.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
}



void MainWindow::on_rechercher_clicked()
{

    employe P("1", "", "", 1, 1, "", "", "", "");
    QString cas =ui->lineEdit_19->text();
    P.rechercher(ui->tableView_2,cas);
    if(ui->lineEdit_19->text().isEmpty())
    {
        ui->tableView_2->setModel(P.afficher());
    }

}
void MainWindow::on_pushButton_2_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setHeaderData(0, Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("TELEPHONE"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("SALAIRE"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("GENRE"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(7, Qt::Horizontal,QObject::tr("PRESENCE"));
    model->setHeaderData(8, Qt::Horizontal,QObject::tr("SPECIALITE"));

    ui->tableView_2->setModel(model);

    QSqlQuery query;

    QString orderByClause;

    if (ui->comboBox->currentText() == "salaire")
        orderByClause = "ORDER BY salaire ASC";
    else if (ui->comboBox->currentText() == "presence")
        orderByClause = "ORDER BY presence ASC";
    else if (ui->comboBox->currentText() == "id_employe")
        orderByClause = "ORDER BY id_employe ASC";


    query.prepare("SELECT * FROM employe " + orderByClause);

    if (query.exec() && query.next())
    {
        model->setQuery(query);
        ui->tableView_2->setModel(model);
    }
}
void MainWindow::on_pb_PDF_clicked()
{
    QPdfWriter pdf("C:/Users/nour/Desktop/Nour (2)/Nour/Nour/employes.pdf");
    QPainter painter(&pdf);
    int i = 4000; // Position verticale initiale

    painter.setPen(Qt::blue);
    painter.setFont(QFont("Time New Roman", 25));
    painter.drawText(2000, 1000, "Liste des Employés");

    painter.setPen(Qt::black);
    painter.setFont(QFont("Time New Roman", 12));
    painter.drawRect(100, 1500, 9600, 500);
    painter.drawText(200, 1800, "ID");
    painter.drawText(1200, 1800, "Nom");
    painter.drawText(2200, 1800, "Prénom");
    painter.drawText(4200, 1800, "Téléphone");
    painter.drawText(6200, 1800, "Salaire");

    QSqlQuery query;
    query.prepare("SELECT * FROM employe");
    if (query.exec()) {
        while (query.next()) {
            painter.drawText(200, i, query.value(0).toString());
            painter.drawText(1200, i, query.value(1).toString());
            painter.drawText(2200, i, query.value(2).toString());
            painter.drawText(4200, i, query.value(3).toString());
            painter.drawText(6200, i, query.value(4).toString());
            i += 350;
        }
    }

    QMessageBox::information(this, "PDF généré", "Le fichier PDF a été enregistré avec succès.");
    QMessageBox::information(this, "PDF", "Bouton PDF cliqué !");
}
#include <QSqlQuery>
#include <QSqlError>

void MainWindow::on_pb_stat_clicked()
{
    // Créer un modèle pour afficher les résultats de la requête
    QSqlQuery query;

    // Requête pour les employés avec Salaire > 600
    query.exec("SELECT * FROM employe WHERE Salaire > 600");
    if (query.lastError().isValid()) {
        qDebug() << "Erreur SQL (Salaire > 600):" << query.lastError().text();
    }
    int id = query.size();  // Utilise `size()` pour obtenir le nombre de lignes retournées

    // Requête pour les employés avec Salaire BETWEEN 400 AND 600
    query.exec("SELECT * FROM employe WHERE Salaire BETWEEN 400 AND 600");
    if (query.lastError().isValid()) {
        qDebug() << "Erreur SQL (Salaire entre 400 et 600):" << query.lastError().text();
    }
    int idd = query.size();

    // Requête pour les employés avec Salaire < 400
    query.exec("SELECT * FROM employe WHERE Salaire < 400");
    if (query.lastError().isValid()) {
        qDebug() << "Erreur SQL (Salaire < 400):" << query.lastError().text();
    }
    int iddd = query.size();

    // Calcul du total
    float total = id + idd + iddd;

    // Protection contre la division par zéro
    if (total == 0) {
        qDebug() << "Aucun employé trouvé dans les critères.";
        return;  // On quitte la fonction si aucune donnée n'est présente.
    }

    // Calcul des pourcentages
    QString a = QString("moins de 50M: %1%").arg((id * 100) / total, 0, 'f', 2);
    QString b = QString("entre 10M et 50M: %1%").arg((idd * 100) / total, 0, 'f', 2);
    QString c = QString("+50M: %1%").arg((iddd * 100) / total, 0, 'f', 2);

    // Création de la série pour le graphique circulaire
    QPieSeries *series = new QPieSeries();
    series->append(a, id);
    series->append(b, idd);
    series->append(c, iddd);

    // Personnalisation des tranches du graphique
    for (int i = 0; i < series->count(); ++i) {
        QPieSlice *slice = series->slices().at(i);
        slice->setLabelVisible(true);  // Assurer que l'étiquette est visible.
        if (i == 0) slice->setBrush(QColor("#3498db"));  // Couleur pour Salaire > 600
        if (i == 1) slice->setBrush(QColor("#2ecc71"));  // Couleur pour Salaire entre 400 et 600
        if (i == 2) slice->setBrush(QColor("#e74c3c"));  // Couleur pour Salaire < 400
    }

    // Création du graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(QString("Pourcentage par Salaire: Nombre des Employés %1").arg(total));
    chart->legend()->hide();  // Masquer la légende si nécessaire

    // Création de la vue du graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(1000, 500);  // Taille du graphique
    chartView->show();  // Affichage du graphique
}


void MainWindow::on_pushButton_ask_clicked()
{
    QString userQuestion = ui->lineEdit_user->text().trimmed();
    if (userQuestion.isEmpty()) {
        return;
    }

    // Ajouter la question de l'utilisateur à la zone de chat
    ui->textEdit_chat->append("Vous : " + userQuestion);

    // Obtenir une réponse du chatbot
    QString response = getResponse(userQuestion);
    ui->textEdit_chat->append("Chatbot : " + response);

    // Effacer la zone de saisie
    ui->lineEdit_user->clear();
}

QString MainWindow::getResponse(const QString &question)
{
    // Convertir la question en minuscule pour une vérification insensible à la casse
    QString lowerQuestion = question.toLower();

    // Vérification des mots-clés pour donner des réponses appropriées
    if (lowerQuestion.contains("horaires")) {
        return "Les horaires de travail sont de 8h à 17h du lundi au vendredi.";
    }
    else if (lowerQuestion.contains("congé")) {
        return "Vous devez remplir le formulaire de demande de congé et l'envoyer au responsable des ressources humaines.";
    }
    if (lowerQuestion.contains("bonjour") || lowerQuestion.contains("salut")) {
        return "Bonjour ! Comment puis-je vous aider ?";
    }
    else if (lowerQuestion.contains("comment ça va")) {
        return "Je vais bien, merci ! Et vous ?";
    }
    else if (lowerQuestion.contains("où est la salle de réunion")) {
        return "La salle de réunion est au premier étage, à gauche du hall.";
    }
    else if (lowerQuestion.contains("comment accéder au wifi")) {
        return "Vous pouvez accéder au wifi en utilisant le mot de passe fourni par le service informatique.";
    }
    else if (lowerQuestion.contains("où est le bureau des ressources humaines")) {
        return "Le bureau des ressources humaines est au premier étage.";
    }
    else if (lowerQuestion.contains("comment signaler un problème technique")) {
        return "Pour signaler un problème technique, veuillez contacter le service informatique par e-mail.";
    }
    else if (lowerQuestion.contains("que faire en cas d'absence")) {
        return "Veuillez signaler votre absence à votre superviseur dès que possible.";
    }
    else if (lowerQuestion.contains("quand est la prochaine réunion")) {
        return "La prochaine réunion est prévue pour lundi à 10h.";
    }
    else if (lowerQuestion.contains("quelles sont les heures supplémentaires")) {
        return "Les heures supplémentaires sont rémunérées à un taux de 1,5 fois le tarif horaire.";
    }
    else if (lowerQuestion.contains("quelles sont les vacances annuelles")) {
        return "Les employés ont droit à 25 jours de congés payés par an.";
    }
    else if (lowerQuestion.contains("qui contacter pour des questions de rh")) {
        return "Vous pouvez contacter le département des ressources humaines par e-mail ou téléphone.";
    }
    else if (lowerQuestion.contains("quelles sont mes heures")) {
        return "Vous pouvez consulter vos heures sur le portail des employés.";
    }
    else if (lowerQuestion.contains("pause")) {
        return "Les employés ont droit à une pause de 30 minutes après 4 heures de travail.";
    }
    else if (lowerQuestion.contains("télétravail")) {
        return "La politique de télétravail permet aux employés de travailler à distance jusqu'à 2 jours par semaine.";
    }
    else if (lowerQuestion.contains("quand sont les devoirs distribués")) {
        return "Les devoirs sont généralement distribués chaque vendredi.";
    }
    else if (lowerQuestion.contains("quel est le format des devoirs")) {
        return "Les devoirs doivent être soumis au format PDF, sauf indication contraire.";
    }
    else if (lowerQuestion.contains("comment soumettre un devoir")) {
        return "Les devoirs doivent être soumis via la plateforme d'apprentissage avant la date limite.";
    }
    else if (lowerQuestion.contains("y a-t-il un délai pour les devoirs")) {
        return "Oui, tous les devoirs doivent être soumis avant 17h00 le jour de la date limite.";
    }
    else if (lowerQuestion.contains("que faire si je ne peux pas rendre un devoir à temps")) {
        return "Si vous ne pouvez pas rendre un devoir à temps, veuillez en informer votre enseignant à l'avance.";
    }
    else if (lowerQuestion.contains("comment recevoir des devoirs en retard")) {
        return "Vous pouvez demander les devoirs en retard à votre enseignant après avoir informé que vous avez manqué la date limite.";
    }
    else if (lowerQuestion.contains("peut-on demander des éclaircissements sur les devoirs")) {
        return "Oui, vous pouvez demander des éclaircissements sur les devoirs pendant les heures de bureau de l'enseignant.";
    }
    else if (lowerQuestion.contains("comment savoir les devoirs à rendre")) {
        return "Les devoirs à rendre sont listés sur la plateforme d'apprentissage sous la section 'Devoirs'.";
    }
    else if (lowerQuestion.contains("qui note les devoirs")) {
        return "Tous les devoirs sont notés par l'enseignant qui les a assignés.";
    }
    else if (lowerQuestion.contains("comment consulter mes notes de devoirs")) {
        return "Vous pouvez consulter vos notes de devoirs sur la plateforme d'apprentissage après qu'elles ont été publiées.";
    }
    else if (lowerQuestion.contains("quel est le barème de notation des devoirs")) {
        return "Le barème de notation des devoirs est communiqué au début du cours ou se trouve sur la plateforme d'apprentissage.";
    }
    else if (lowerQuestion.contains("peut-on faire des devoirs en groupe")) {
        return "Cela dépend des consignes de l'enseignant. Vérifiez les instructions pour chaque devoir.";
    }
    else if (lowerQuestion.contains("où se trouve la liste des devoirs")) {
        return "La liste des devoirs se trouve sur la page d'accueil de la plateforme d'apprentissage.";
    }
    else if (lowerQuestion.contains("comment contacter l'enseignant pour des devoirs")) {
        return "Vous pouvez contacter l'enseignant par e-mail ou durant les heures de bureau pour des questions sur les devoirs.";
    }
    else if (lowerQuestion.contains("y a-t-il des exemples de devoirs")) {
        return "Des exemples de devoirs peuvent être trouvés dans la section 'Ressources' de la plateforme d'apprentissage.";
    }
    else if (lowerQuestion.contains("comment imprimer un devoir")) {
        return "Les devoirs peuvent être imprimés à partir de votre appareil via la fonction d'impression.";
    }
    else if (lowerQuestion.contains("qui est responsable des devoirs")) {
        return "Chaque enseignant est responsable des devoirs qu'il assigne.";
    }
    else if (lowerQuestion.contains("les devoirs doivent-ils être manuscrits")) {
        return "La plupart des devoirs doivent être tapés, sauf indication contraire.";
    }
    else if (lowerQuestion.contains("comment gérer plusieurs devoirs")) {
        return "Il est conseillé de planifier votre temps et de définir des priorités pour chaque devoir.";
    }
    else if (lowerQuestion.contains("peut-on avoir des retours sur les devoirs rendus")) {
        return "Oui, les enseignants fournissent généralement des retours détaillés sur les devoirs rendus.";
    }
    else if (lowerQuestion.contains("quand sont publiés les devoirs à rendre")) {
        return "Les devoirs sont publiés au début de chaque semaine sur la plateforme d'apprentissage.";
    }
    else if (lowerQuestion.contains("merci") || lowerQuestion.contains("je te remercie")) {
        return "Avec plaisir ! N'hésitez pas à demander si vous avez besoin de plus d'aide.";
    }
    else if (lowerQuestion.contains("au revoir") || lowerQuestion.contains("à bientôt")) {
        return "Au revoir ! Passez une bonne journée.";
    }

    else if (lowerQuestion.contains("pause")) {
        return "Les employés ont droit à une pause de 30 minutes après 4 heures de travail.";
    }
    else if (lowerQuestion.contains("télétravail")) {
        return "La politique de télétravail permet aux employés de travailler à distance jusqu'à 2 jours par semaine.";
    }
    else if (lowerQuestion.contains("formation")) {
        return "Nous offrons des formations internes et externes sur différents sujets.";
    }
    else if (lowerQuestion.contains("service informatique")) {
        return "Le service informatique se trouve au deuxième étage, à côté de la salle de réunion.";
    }
    else {
        // Réponse par défaut si aucune correspondance n'est trouvée
        return "Désolé, je ne connais pas la réponse à cette question.";
    }
}


void MainWindow::on_pushButton_send_2_clicked()
{
    // Get the sender from comboBox_7
    QString sender = ui->comboBox_7->currentText();

    // Check if a sender is selected
    if (sender.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un expéditeur.");
        return;
    }

    // Get the message from the input field
    QString message = ui->lineEdit_message_2->text().trimmed();


    // Insert the message into the database
    QSqlQuery query;
    query.prepare("INSERT INTO messages (sender, message) VALUES (:sender, :message)");
    query.bindValue(":sender", sender);
    query.bindValue(":message", message);

    // Execute the query and check for errors
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Impossible d'envoyer le message !");
        return;
    }

    // Clear the message input field after sending
    ui->lineEdit_message_2->clear();

    // Reload the messages to show the new one
    loadMessages();
}

void MainWindow::loadMessages()
{
    // Ensure the database connection is open
    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "Database not open! Check your connection.";
        return;
    }

    // Execute the query to retrieve messages
    QSqlQuery query;
    if (!query.exec("SELECT timestamp, sender, message FROM messages ORDER BY timestamp ASC")) {
        qDebug() << "Failed to execute query:" << query.lastError();
        return;
    }

    // Clear the display widget before loading new messages
    ui->messageBrowser->clear(); // Assuming a QTextBrowser named messageBrowser

    // Iterate over the query results and append them to the display widget
    while (query.next()) {
        QString timestamp = query.value(0).toString();
        QString sender = query.value(1).toString();
        QString message = query.value(2).toString();

        // Format and append the message
        QString formattedMessage = QString("[%1] %2: %3").arg(timestamp, sender, message);
        ui->messageBrowser->append(formattedMessage);
    }
}

void MainWindow::on_pushButton_delete_clicked()
{
    // Get the message from the input field (or select it from the list or browser)
    QString messageToDelete = ui->lineEdit_message_2->text().trimmed();
    // Execute the query to delete the message from the database
    QSqlQuery query;
    query.prepare("DELETE FROM messages WHERE message = :message");
    query.bindValue(":message", messageToDelete);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Impossible de supprimer le message !");
        return;
    }

    // Clear the message input field after deletion
    ui->lineEdit_message_2->clear();

    // Reload the messages to reflect the deletion
    loadMessages();
}
//jdid
void MainWindow::onRestorePassword()
{
QString email = ui->email->text().trimmed();
    // Validate email
    if(email.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter your email address");
        return;
    }

    // Generate new password
    QString newPassword = generateRandomPassword();

    // Persist the new password (in a real app, this would be in a database)
    if(!persistNewPassword(email, newPassword)) {
        QMessageBox::critical(this, "Error", "Failed to update password");
        return;
    }

    // Send email with new password
    QString object = "Your New Password";
    QString body = QString("Your new password is: %1\n\nPlease change it after logging in.").arg(newPassword);

    int result = Email::sendEmail(email,object,body);

    // int result = Email::sendEmail(email,object,body);
    if(result == 0) {
        QMessageBox::information(this, "Success", "A new password has been sent to your email address");
    } else {
        QMessageBox::critical(this, "Error", "Failed to send email with new password");
    }
}

QString MainWindow::generateRandomPassword(int length)
{
    const QString possibleCharacters =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()";

    QString randomPassword;
    QRandomGenerator *generator = QRandomGenerator::global();

    for(int i = 0; i < length; ++i) {
        int index = generator->bounded(possibleCharacters.length());
        QChar nextChar = possibleCharacters.at(index);
        randomPassword.append(nextChar);
    }

    return randomPassword;
}

bool MainWindow::persistNewPassword(const QString& email, const QString& newPassword)
{
    // Vérifie si l'utilisateur existe
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT id_employe FROM employe WHERE adresseemploye = :email");
    checkQuery.bindValue(":email", email);

    if (!checkQuery.exec()) {
        qDebug() << "Erreur lors de la recherche de l'utilisateur :" << checkQuery.lastError().text();
        return false;
    }

    if (!checkQuery.next()) {
        qDebug() << "Aucun utilisateur trouvé avec l'email :" << email;
        return false;
    }

    QString id_employe = checkQuery.value(0).toString();

    // Mise à jour du mot de passe
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE employe SET motdepasse = :newPassword WHERE adresseemploye = :email");
    updateQuery.bindValue(":newPassword", newPassword);
    updateQuery.bindValue(":email", email);

    if (!updateQuery.exec()) {
        qDebug() << "Erreur lors de la mise à jour du mot de passe :" << updateQuery.lastError().text();
        return false;
    }

    qDebug() << "Mot de passe mis à jour avec succès pour l'utilisateur avec l'ID :" << id_employe;
    return true;
}




void MainWindow::on_restore_clicked()
{
    onRestorePassword();
}

