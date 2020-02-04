#include "ph.hpp"
#include "fromqtgui.hpp"

fromQtGUI::fromQtGUI(QWidget *parent)
	: QMainWindow(parent)
{ 
	ui.setupUi(this);

	QFrame* pFrame = new QFrame(this);
	pFrame->setStyleSheet("background-color: rgb(50, 50, 50); color: rgb(255, 255, 255); font-size: 12px");
	this->setCentralWidget(pFrame);
	QMenu* mnuFile = menuBar()->addMenu(u8"Настройки");
	
	QMenu* mnuRef = menuBar()->addMenu(u8"Справка");
	QAction *actionExit = new QAction(u8"Выход", this);
	QAction *actionConn = new QAction(u8"Подключение", this);
	QAction *actionXbiPath = new QAction(u8"Путь экспорта!", this);

	mnuFile->addAction(actionExit);
	mnuFile->addAction(actionConn);
	mnuFile->addAction(actionXbiPath);

	this->generateB = new QPushButton(u8"Сгенерировать Приборы", this);
	this->generateB->setFixedWidth(200);
	this->generateB->setFixedHeight(30);
	//QObject::connect(generateB, &QPushButton::clicked, this, &DdeMainWindow::generateXbi);


	QLineEdit *searchLine = new QLineEdit(this);
	searchLine->setFixedWidth(300);
	searchLine->setFixedHeight(30);
	searchLine->setStyleSheet("background-color: rgb(100, 100, 100);");
	QBoxLayout* searchLayout = new QBoxLayout(QBoxLayout::LeftToRight);
	searchLayout->addWidget(searchLine);

	QPushButton *searchBtn = new QPushButton(this);
	searchBtn->setText(u8"Добавить прибор_");
	searchBtn->setFixedHeight(30);
	searchBtn->setFixedWidth(150);
	searchLayout->addWidget(searchBtn);
	searchLayout->addSpacing(800);

	this->configxTbl = new QTableView();
	this->conceptxTbl = new QTableView();
	this->setxTbl = new QTableView();
	this->mainTLayout = new QBoxLayout(QBoxLayout::LeftToRight);

	this->mainTLayout->addWidget(this->configxTbl);
	this->mainTLayout->addWidget(this->conceptxTbl);
	this->mainTLayout->addWidget(this->setxTbl);
	
	QBoxLayout* btnLayout = new QBoxLayout(QBoxLayout::LeftToRight);
	btnLayout->addSpacing(1200);
	btnLayout->addWidget(this->generateB);

	QBoxLayout* bxLayout = new QBoxLayout(QBoxLayout::TopToBottom, pFrame);

	
	
	bxLayout->addLayout(searchLayout);
	bxLayout->addLayout(this->mainTLayout);
	bxLayout->addLayout(btnLayout);
	

	QBoxLayout *statusLayout = new QBoxLayout(QBoxLayout::LeftToRight);
	this->status = new QTextEdit(this);
	this->status->setStyleSheet("background-color: #656565; color: #f5f5f5; ");
	this->status->setFixedHeight(15);
	this->status->setReadOnly(true);
	this->status->setContentsMargins(0, -5, 0, 0);

	QPushButton *copyLogB = new QPushButton();
	copyLogB->setText("...");
	copyLogB->setFixedWidth(15);
	copyLogB->setFixedHeight(15);
	statusLayout->addWidget(this->status);

	this->statusBar()->addWidget(this->status, 1);
	this->statusBar()->addWidget(copyLogB, 0);

	centralWidget()->layout()->setContentsMargins(5, 2, 5, 5);

	this->setWindowTitle(u8"Редактор параметров приборов");
	this->resize(1200, 700);
}
