//---- include section ------
#include <SFML/Graphics.hpp>
#include <iostream>
#include "EditController.h"
#include "Resources.h"
#include "Utilities.h"

//---- using section --------
using std::cin;
using std::cout;
using std::endl;

EditController::EditController()
{
	// load recources (images and fonts)
	Resources::loadResources();
}

void EditController::run()
{
	EditOption editOption = SELECT_CHAR;
	Character selectCharacter = EMPTY;

	// load level from file
	LevelFileManager lfm;

	// create window
	sf::VideoMode screenSize(1000, 600);
	sf::RenderWindow window(screenSize, "Bomberman Editor");

	// load icon
	window.setIcon(Resources::Images::BombermanIcon.getSize().x, Resources::Images::BombermanIcon.getSize().y,
		           Resources::Images::BombermanIcon.getPixelsPtr());

	// create board of editor
	Board board(window);

	// try load level from file or create new map
	if (!lfm.fileExists())
		readLevelSize(window, board);
	else
		lfm.loadLevelMap(board.getLevelMap());

	// handle board events
	handleEvents(board, lfm, editOption, selectCharacter);

	// run window
	runWindow(window, board);
}

void EditController::readLevelSize(RenderWindow &window, Board &board)
{
	// hide board
	board.hide();

	// add message to window
	TextView message(window, "Please enter size at CMD!");
	message.setBound(Vector2f(0, 0), window.getSize().x, window.getSize().y);
	message.setTextColor(Color::Yellow);

	// refresh window
	window.clear();
	message.draw();
	window.display();

	// get numbers from standard input
	cout << "Please enter number of rows and number of columns:" << endl;
	int numOfRows, numOfCols;
	cin >> numOfRows >> numOfCols;
	board.getLevelMap().setMapSize(Vector2i(numOfRows, numOfCols));

	// show board
	board.show();
}

void EditController::handleEvents(Board &board, LevelFileManager &lfm, EditOption &editOption, Character &selectCharacter)
{
	handleMenuEvents(board, lfm, editOption, selectCharacter);
	handleCharPanelEvents(board, lfm, editOption, selectCharacter);
	handleLevelMapEvents(board, lfm, editOption, selectCharacter);
}

void EditController::handleMenuEvents(Board &board, LevelFileManager &lfm, EditOption &editOption, Character &selectCharacter)
{
	// handle "new" button at menu
	board.getMenu().getNewButton().addEnterListener(View::EnterHandler::Listener([](View &view) {
		view.getBackground().setColor(Toolbar::BT_FOCUS_BACK_COLOR);
	}));
	board.getMenu().getNewButton().addLeaveListener(View::LeaveHandler::Listener([](View &view) {
		view.getBackground().setColor(Toolbar::BT_BACK_COLOR);
	}));
	board.getMenu().getNewButton().addClickListener(View::ClickHandler::Listener([this, &board, &lfm, &editOption, &selectCharacter](View &view) {
		this->readLevelSize(view.getWindow(), board);
		this->handleLevelMapEvents(board, lfm, editOption, selectCharacter);
	}));

	// handle "save" button at menu
	board.getMenu().getSaveButton().addEnterListener(View::EnterHandler::Listener([](View &view) {
		view.getBackground().setColor(Toolbar::BT_FOCUS_BACK_COLOR);
	}));
	board.getMenu().getSaveButton().addLeaveListener(View::LeaveHandler::Listener([](View &view) {
		view.getBackground().setColor(Toolbar::BT_BACK_COLOR);
	}));
	board.getMenu().getSaveButton().addClickListener(View::ClickHandler::Listener([&board, &lfm](View &view) {
		lfm.saveLevelMap(board.getLevelMap());
		cout << "level has been saved successfully" << endl;
	}));

	// handle "delete" button at menu
	board.getMenu().getDeleteButton().addEnterListener(View::EnterHandler::Listener([&editOption](View &view) {
		if (editOption == SELECT_CHAR) {
			view.getBackground().setColor(Toolbar::BT_FOCUS_BACK_COLOR);
		}
		else {
			view.getBackground().setColor(Toolbar::BT_SELFCS_BACK_COLOR);
		}
	}));
	board.getMenu().getDeleteButton().addLeaveListener(View::LeaveHandler::Listener([&editOption](View &view) {
		if (editOption == SELECT_CHAR) {
			view.getBackground().setColor(Toolbar::BT_BACK_COLOR);
		} else {
			view.getBackground().setColor(Toolbar::BT_SEL_BACK_COLOR);
		}
	}));
	board.getMenu().getDeleteButton().addClickListener(View::ClickHandler::Listener
	([&board, &editOption, &selectCharacter](View &view) {
		if (editOption == SELECT_CHAR) {
			if (selectCharacter != EMPTY)
				board.getCharPanel().getCharacterButton(selectCharacter).getBackground().setColor(CharacterPanel::BT_BACK_COLOR);
			editOption = DELETE_CHAR;
			selectCharacter = EMPTY;
			view.getBackground().setColor(Toolbar::BT_SEL_BACK_COLOR);
		}
		else {
			editOption = SELECT_CHAR;
			view.getBackground().setColor(Toolbar::BT_BACK_COLOR);
		}
	}));
}

void EditController::handleCharPanelEvents(Board &board, LevelFileManager &lfm, EditOption &editOption, Character &selectCharacter)
{
	// handle characters buttons at character panel
	board.getCharPanel().forEach([&editOption, &selectCharacter, &board](CharacterButton &charButton) {
		charButton.addClickListener(View::ClickHandler::Listener([&editOption, &selectCharacter, &charButton, &board](View &view) {
			if (selectCharacter == charButton.getCharacter()) {
				selectCharacter = EMPTY;
				charButton.getBackground().setColor(CharacterPanel::BT_BACK_COLOR);
			}
			else {
				if (editOption == DELETE_CHAR)
				{
					editOption = SELECT_CHAR;
					board.getMenu().getDeleteButton().getBackground().setColor(Toolbar::BT_BACK_COLOR);
				}
				if (selectCharacter != EMPTY)
					board.getCharPanel().getCharacterButton(selectCharacter).getBackground().setColor(CharacterPanel::BT_BACK_COLOR);

				selectCharacter = charButton.getCharacter();
				charButton.getBackground().setColor(CharacterPanel::BT_SEL_BACK_COLOR);
			}
		}));
		charButton.addEnterListener((View::EnterHandler::Listener([&charButton, &editOption, &selectCharacter](View &view) {
			if ((editOption == SELECT_CHAR)&&(selectCharacter == charButton.getCharacter())) {
				view.getBackground().setColor(CharacterPanel::BT_SELFCS_BACK_COLOR);
			}
			else {
				view.getBackground().setColor(CharacterPanel::BT_FOCUS_BACK_COLOR);
			}
		})));
		charButton.addLeaveListener((View::LeaveHandler::Listener([&charButton, &editOption, &selectCharacter](View &view) {
			if ((editOption == SELECT_CHAR) && (selectCharacter == charButton.getCharacter())) {
				view.getBackground().setColor(CharacterPanel::BT_SEL_BACK_COLOR);
			}
			else {
				view.getBackground().setColor(CharacterPanel::BT_BACK_COLOR);
			}
		})));
	});
}

void EditController::handleLevelMapEvents(Board &board, LevelFileManager &lfm, EditOption &editOption, Character &selectCharacter)
{
	// handle characters views of level map
	board.getLevelMap().forEach([&editOption, &selectCharacter, &board](CharacterView &charView, const Cell &cell) {
		charView.addClickListener(View::ClickHandler::Listener([&editOption, &selectCharacter, &board, &charView](View &view) {
			if (editOption == DELETE_CHAR) {
				charView.setCharacter(EMPTY);
			}
			else {
				if (selectCharacter != EMPTY) {
					if (charView.getCharacter() == EMPTY) {
						if (selectCharacter == ROBOT) {
							Cell robotCell;
							if (Utilites::isRobotInMap(board.getLevelMap(), robotCell)) {
								board.getLevelMap().getCharacterView(robotCell).setCharacter(EMPTY);
							}
						}
						if (selectCharacter == EXIT_DOOR) {
							Cell exitDoorCell;
							if (Utilites::isExitDoorInMap(board.getLevelMap(), exitDoorCell)) {
								board.getLevelMap().getCharacterView(exitDoorCell).setCharacter(EMPTY);
							}
						}

						charView.setCharacter(selectCharacter);
					}
				}
			}
		}));
		charView.addEnterListener(View::EnterHandler::Listener([&editOption, &selectCharacter, &board, &charView](View &view) {
			if (editOption == DELETE_CHAR) {
				charView.getBackground().setColor(Color::Blue);
			}
			else {
				if (selectCharacter != EMPTY) {
					if (charView.getCharacter() == EMPTY) {
						charView.getBackground().setColor(Color::Green);
					}
					else {
						charView.getBackground().setColor(Color::Red);
					}
				}
			}
		}));
		charView.addLeaveListener(View::LeaveHandler::Listener([](View &view) {
			view.getBackground().setColor(Color::Transparent);
		}));
	});
}

void EditController::runWindow(RenderWindow &window, Board &board)
{
	// run window
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();
			board.handleEvent(event); // here we handle board events
		}

		window.clear();
		board.draw(); // here we draw the board
		window.display();
	}
}
