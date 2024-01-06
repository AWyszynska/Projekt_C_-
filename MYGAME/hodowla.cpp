
#include "hodowla.h" 



Hodowla::Hodowla(sf::RenderWindow& window) : window(window),
exit(window, sf::Vector2f(50, 50), sf::Vector2f(100, 100)),
zlotowkiFile("zlotowki_value.txt"),speedMultiplier(0.01f),
      czasswinia(20.0f),
      czaskrowa(60.0f),
      czaskura(80.0f),
timerBar(czasswinia, 200.0f, 20.0f, sf::Color::Green),
timerBarkrowa(czaskrowa, 200.0f, 20.0f, sf::Color::Green),
timerBarkura(czaskura, 200.0f, 20.0f, sf::Color::Green) {

     if (!font.loadFromFile("Flottflott.ttf")) {
            std::cout << "Error loading font file!" << std::endl;
        }
     text.setFont(font);
        text.setCharacterSize(30);
        text.setFillColor(sf::Color::Black);
 zlotowkiText.setFont(font);
    zlotowkiText.setCharacterSize(30);
    zlotowkiText.setFillColor(sf::Color::Black);
    zlotowkiText.setPosition(1000, 90); 
    zlotowkiText.setString("Zlotowki: " + std::to_string(zlotowkiValue));
    if (zlotowkiFile.is_open()) {
        zlotowkiFile >> zlotowkiValue;
        zlotowkiFile.close();
    }

if (!backgroundTexture.loadFromFile("hodowlazdj/hodowla1.png")) {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
    background.setTexture(backgroundTexture);
    if (!exittextur.loadFromFile("aazdj/wyjscie.png")) {
    std::cout<<"blad\n";
    }
    exit.setTexture(exittextur);

    if (!pasek_zdj.loadFromFile("aazdj/pasek.png"))
    {
        std::cerr << "Błąd podczas wczytywania." << std::endl;
    }
    pasek.setTexture(pasek_zdj);
    pasek.setPosition(260.0f, 680.0f);
    pasek.setScale(0.9f, 0.9f);
    if (!skrzynkazdj.loadFromFile("aazdj/skrzynka.png")) {
    std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
    skrzynka.setTexture(skrzynkazdj);
    skrzynka.setPosition(950.0f, 0.0f);
    skrzynka.setScale(0.5f, 0.5f);

    if (!plotzdj.loadFromFile("hodowlazdj/plot.png")) {
    std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
    plot.setTexture(plotzdj);
    plot.setPosition(0.0f, 465.0f);
    plot.setScale(1.0f, 1.0f);
size = sf::Vector2f(0.15f, 0.15f);
targetSize = size;
    timerBar.setPosition(100.0f, 390.0f);
    timerBarkrowa.setPosition(500.0f, 390.0f);
    timerBarkura.setPosition(900.0f, 390.0f);
    initialPositionKrowa = sf::Vector2f(370.f, 400.f);
    initialPositionSwinia = sf::Vector2f(0.f, 420.f); 
    initialPositionKura = sf::Vector2f(440.f, 700.f); 
    if (!swiniaEndTexture.loadFromFile("hodowlazdj/swinka1zdechla.png")) {
    std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
    if (!krowaEndTexture.loadFromFile("hodowlazdj/krowa4zdechla.png")) {
    std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
    if (!kuraEndTexture.loadFromFile("hodowlazdj/kura1zdechla.png")) {
    std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }

}

void Hodowla::renderTopasek(){
    std::ifstream file("wypisz_values.txt");
    if (!file.is_open()) {
        std::cerr << "Nie można otworzyć pliku!" << std::endl;
    }
    while (file >> Signs) {
        if (Signs != ' ') {
            ReadSigns.push_back(Signs);
        }
    }
  file.close();        

        std::ifstream files("letter_values.txt");
    if (!files.is_open()) {
        std::cerr << "Nie można otworzyć pliku!" << std::endl;
    }
    while (files >> valuess) {
        if (valuess != ' ') {
           Readvalues.push_back(valuess);
        }
    }
  files.close(); 
}
void Hodowla::addstorage(){
    if (!pointsphoto.loadFromFile("aazdj/kropki.png"))
    {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
    points.setTexture(pointsphoto);
    points.setPosition(830.0f, 725.0f);
    points.setScale(0.4f, 0.4f);
    window.draw(points);
}

void Hodowla::addToPasek(){
int position = 270;
    int interval = 150;
int displayedValues = 0;
int displayedVal = 0;
    for (char znak : ReadSigns) {
        if (displayedValues >= 4) {
            break; // Przerwij pętlę po wyświetleniu 3 wartości
        }
        if (znak == 'P') {
           
            if (obraz1.loadFromFile("aazdj/nasiono1.png")) {
                ziarenko.setTexture(obraz1);
                ziarenko.setPosition(position,700); 
                //ziarenko.setScale(size);
                window.draw(ziarenko);
                displayedValues++;
                
            }
        } else if (znak == 'M') {
           
            if (obraz2.loadFromFile("aazdj/nasionamarchewka.png")) {
                sf::Sprite sprite(obraz2);
                sprite.setPosition(position,700); 
                sprite.setScale(0.7f, 0.7f);
                window.draw(sprite);
                displayedValues++;
            }
        } else if (znak == 'T') {

            if (obraz3.loadFromFile("aazdj/nasionatruskawka.png")) {
                sf::Sprite sprite(obraz3);
                sprite.setPosition(position + 10,700); 
                sprite.setScale(0.7f, 0.7f);
                window.draw(sprite);
                displayedValues++;
            }
        }
                else if (znak == 'C') {

            if (carrottolinephoto.loadFromFile("aazdj/carrot.png")) {
                //sf::Sprite sprite3(obraz3);
               carrottoline.setTexture(carrottolinephoto);
                carrottoline.setPosition(position - 5 ,700); 
                carrottoline.setScale(0.25f, 0.25f);
                window.draw(carrottoline);
                displayedValues++;


            }
        }
        else if (znak == 'S') {

            if (strawberrytolinephoto.loadFromFile("aazdj/truskawka.png")) {
                //sf::Sprite sprite3(obraz3);
                strawberrytoline.setTexture(strawberrytolinephoto);
                strawberrytoline.setPosition(position - 10,700); 
                strawberrytoline.setScale(0.3f, 0.3f);
                window.draw(strawberrytoline);
                displayedValues++;


            }
        }
        else if (znak == 'J') {

            if (obraz4.loadFromFile("zdjeciasad/nasionajablka.png")) {
                sf::Sprite sprite(obraz4);
                sprite.setPosition(position,690); 
                sprite.setScale(0.4f, 0.4f);
                window.draw(sprite);
                displayedValues++;
            }
        }
        else if (znak == 'G') {

            if (obraz5.loadFromFile("zdjeciasad/nasionagruszki.png")) {
                 sf::Sprite sprite(obraz5);
                sprite.setPosition(position,690); 
                sprite.setScale(0.35f, 0.35f);
                window.draw(sprite);
                displayedValues++;
            }
        }
        else if (znak == 'Z') {

            if (obraz6.loadFromFile("zdjeciasad/nasionkosliwa.png")) {
                sf::Sprite sprite(obraz6);
                sprite.setPosition(position,690); 
                sprite.setScale(0.4f, 0.4f);
                window.draw(sprite);
                displayedValues++;
            }
        }
                else if (znak == 'A') {//F

            if (obraz7.loadFromFile("zdjeciasad/jablkozdjecie.png")) {
                sf::Sprite sprite(obraz7);
                sprite.setPosition(position,690); 
                sprite.setScale(0.2f, 0.2f);
                window.draw(sprite);
                displayedValues++;
            }
        }
        else if (znak == 'E') {//gruszka

            if (obraz8.loadFromFile("zdjeciasad/gruszkazdjecie.png")) {
                sf::Sprite sprite(obraz8);
                sprite.setPosition(position,690); 
                sprite.setScale(0.2f, 0.2f);
                window.draw(sprite);
                displayedValues++;
            }
        }
        else if (znak == 'F') {//sliwka

            if (obraz9.loadFromFile("zdjeciasad/sliwkazdjecie.png")) {
                sf::Sprite sprite(obraz9);
                sprite.setPosition(position+10,690); 
                sprite.setScale(0.25f, 0.25f);
                window.draw(sprite);
                displayedValues++;
            }
        }
        else if (znak == 'I') {//miedz

            if (obraz9.loadFromFile("kopalnia/sztabkamiedz.png")) {
                sf::Sprite sprite(obraz9);
                sprite.setPosition(position,720); 
                sprite.setScale(0.25f, 0.25f);
                window.draw(sprite);
                displayedValues++;
            }
        }
        else if (znak == 'R') {//srebro

            if (obraz9.loadFromFile("kopalnia/sztabkasrebro.png")) {
                sf::Sprite sprite(obraz9);
                sprite.setPosition(position,720); 
                sprite.setScale(0.25f, 0.25f);
                window.draw(sprite);
                displayedValues++;
            }
        }
        else if (znak == 'L') {//zloto

            if (obraz9.loadFromFile("kopalnia/sztabkazloto.png")) {
                sf::Sprite sprite(obraz9);
                sprite.setPosition(position,720); 
                sprite.setScale(0.25f, 0.25f);
                window.draw(sprite);
                displayedValues++;
            }
        }
        else if (znak == 'D') {//diament

            if (obraz9.loadFromFile("kopalnia/diament.png")) {
                sf::Sprite sprite(obraz9);
                sprite.setPosition(position-10,720); 
                sprite.setScale(0.25f, 0.25f);
                window.draw(sprite);
                displayedValues++;
            }
        }
        position += interval;
    }
            xPos = 220;
        for (int i = 0; i < Readvalues.size(); ++i) {
            xPos += 140;
             if (Readvalues[i] != 0) { 
            text.setString(std::to_string(Readvalues[i]));
            text.setPosition(xPos, 750); 
            window.draw(text);
         }
        }
}


void Hodowla::loadtimes() {
 std::ifstream timeFile("hodowlazdj/czaszamknieciahodowla.txt");
    if (timeFile.is_open()) {
        std::string line;
        if (std::getline(timeFile, line)) {
            std::tm timeInfo = {};

            char day[4], month[4];
            int dayNum, hour, min, sec, year;

            if (std::sscanf(line.c_str(), "%3s %3s %d %d:%d:%d %d",
                            day, month, &dayNum, &hour, &min, &sec, &year) == 7) {

                const char* months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
                const char* days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

                for (int i = 0; i < 12; ++i) {
                    if (month == std::string(months[i])) {
                        timeInfo.tm_mon = i;
                        break;
                    }
                }

                for (int i = 0; i < 7; ++i) {
                    if (day == std::string(days[i])) {
                        timeInfo.tm_wday = i;
                        break;
                    }
                }

                timeInfo.tm_mday = dayNum;
                timeInfo.tm_hour = hour;
                timeInfo.tm_min = min;
                timeInfo.tm_sec = sec;
                timeInfo.tm_year = year - 1900;

                std::time_t timeValue = std::mktime(&timeInfo);
                std::chrono::system_clock::time_point savedTime = std::chrono::system_clock::from_time_t(timeValue);

                std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now();
                difference = currentTime - savedTime;
differenceInSeconds = difference.count();
                
            } else {
                std::cerr << "Failed to parse time!" << std::endl;
            }
        }
        timeFile.close();
    } else {
        std::cerr << "Unable to open the file to read time!" << std::endl;
    }
}





void Hodowla::dodajzwierzeta() {
    if (!krowazdj.loadFromFile("hodowlazdj/krowa1.png")) {
        std::cerr << "Błąd podczas wczytywania." << std::endl;
    }
        krowa.setTexture(krowazdj);
        //krowa.setPosition(0, 360);
        krowa.setScale(0.7f, 0.7f);
    if (!swiniazdj.loadFromFile("hodowlazdj/swinka2.png")) {
        std::cerr << "Błąd podczas wczytywania." << std::endl;
    }
        swinia.setTexture(swiniazdj);
        //krowa.setPosition(0, 360);
        swinia.setScale(0.7f, 0.7f);
        if (!kurazdj.loadFromFile("hodowlazdj/kura2.png")) {
        std::cerr << "Błąd podczas wczytywania." << std::endl;
    }
        kura.setTexture(kurazdj);
        //krowa.setPosition(0, 360);
        kura.setScale(0.7f, 0.7f);

}


void Hodowla::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            savetimeall();
            saveTimeToFile();
                window.close();
            } 
            
        else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                //clickPosition = sf::Mouse::getPosition(window);
                //std::cout << "x: " << clickPosition.x << " y: " << clickPosition.y << std::endl;
            }
        }
        else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            sf::Vector2f mousePos = window.mapPixelToCoords(mousePosition);
            if (exit.isHoveredButton()) {
                switchTofarm();
            }
            else if(points.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
            openwerehouse = !openwerehouse;

            }
                   

 if (ziarenko.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                 if (!ziarenkoClicked) {
                    targetSize = ziarenko.getScale() + sf::Vector2f(0.1f, 0.1f);  
                    ziarenkoClicked = true;
                } else {
                    targetSize = size;  
                    ziarenkoClicked = false;
                }
            }
        else if (ziarenkoClicked && krowa.getGlobalBounds().contains(mousePos)) {
 
                timerBarkrowa.addTime(2.0f); 
                for(int i = 0; i <ReadSigns.size() ; i++){
                         if(ReadSigns[i] == 'P'){
                            if( Readvalues[i] > 1){
                            Readvalues[i] -=1;
                             
                            }
                            else{
                                Readvalues.erase(Readvalues.begin() + i);
                                ReadSigns.erase(ReadSigns.begin() + i);
                            }
                        }

                }
            }
      else if(ziarenkoClicked && swinia.getGlobalBounds().contains(mousePos)){
                timerBar.addTime(2.0f);  
for(int i = 0; i <ReadSigns.size() ; i++){
                         if(ReadSigns[i] == 'P'){
                            if( Readvalues[i] > 1){
                            Readvalues[i] -=1;
                             
                            }
                            else{
                                Readvalues.erase(Readvalues.begin() + i);
                                ReadSigns.erase(ReadSigns.begin() + i);
                            }
                        }

                }
      }
      else if(ziarenkoClicked && kura.getGlobalBounds().contains(mousePos)){
                   timerBarkura.addTime(2.0f); 
for(int i = 0; i <ReadSigns.size() ; i++){
                         if(ReadSigns[i] == 'P'){
                            if( Readvalues[i] > 1){
                            Readvalues[i] -=1;
                             
                            }
                            else{
                                Readvalues.erase(Readvalues.begin() + i);
                                ReadSigns.erase(ReadSigns.begin() + i);
                            }
                        }

                }
      }
    }
}
}

void Hodowla::updateCowMovementKrowa() {
    if (isKrowaAlive) {
    static sf::Clock movementClock; 
    static sf::Clock stopClock; 
    static bool isMoving = true; 
    static bool isStopped = false; 
                static float vx = 1;
     static float vy = 0;
      static float GRAVITY = 0.002;
    static const float moveTime = 3.f; 
    static const float stopTime = 2.5f; 

    if (isMoving) {
        // Krowa się porusza
        sf::Vector2f velocity(vx, vy);
        krowa.move(velocity);

        if (movementClock.getElapsedTime().asSeconds() >= moveTime) {
            isMoving = false;
            isStopped = true;
            vx = -vx; // Zmiana kierunku na przeciwny
            movementClock.restart();
            stopClock.restart();
        }
    } else if (isStopped) {
        // Krowa zatrzymuje się
        if (stopClock.getElapsedTime().asSeconds() >= stopTime) {
            isStopped = false;
            isMoving = true;
            movementClock.restart();
        }
    }

    // Ustawianie tekstury w zależności od kierunku ruchu
    if (vx < 0) {
        if (!krowazdj.loadFromFile("hodowlazdj/krowa4.png")) {
            std::cerr << "Błąd podczas wczytywania." << std::endl;
        }
        krowa.setTexture(krowazdj);
    } else {
        if (!krowazdj.loadFromFile("hodowlazdj/krowa1.png")) {
            std::cerr << "Błąd podczas wczytywania." << std::endl;
        }
        krowa.setTexture(krowazdj);
    }
    }
}



void Hodowla::updateCowMovementKura() {
    if (isKuraAlive) {
static sf::Clock movementClockx; 
    static sf::Clock stopClock; 
    static bool isMoving = true; 
    static bool isStopped = false; 
                static float vx = 1;
     static float vy = 0;
      static float GRAVITY = 0.002;
    static const float moveTime = 3.f; 
    static const float stopTime = 2.f; 

    if (isMoving) {
        // Krowa się porusza
        sf::Vector2f velocity(vx, vy);
        kura.move(velocity);

        if (movementClockx.getElapsedTime().asSeconds() >= moveTime) {
            isMoving = false;
            isStopped = true;
            vx = -vx; // Zmiana kierunku na przeciwny
            movementClockx.restart();
            stopClock.restart();
        }
    } else if (isStopped) {
        // Krowa zatrzymuje się
        if (stopClock.getElapsedTime().asSeconds() >= stopTime) {
            isStopped = false;
            isMoving = true;
            movementClockx.restart();
        }
    }

    // Ustawianie tekstury w zależności od kierunku ruchu
    if (vx < 0) {
        if (!kurazdj.loadFromFile("hodowlazdj/kura1.png")) {
            std::cerr << "Błąd podczas wczytywania." << std::endl;
        }
        kura.setTexture(kurazdj);
    } else {
        if (!kurazdj.loadFromFile("hodowlazdj/kura2.png")) {
            std::cerr << "Błąd podczas wczytywania." << std::endl;
        }
        kura.setTexture(kurazdj);
    }
}
}

void Hodowla::saveAnimalPositions() {
    std::ofstream file("animal_positions.txt");
    if (file.is_open()) {
        file << krowa.getPosition().x << " " << krowa.getPosition().y << std::endl;
        file << swinia.getPosition().x << " " << swinia.getPosition().y << std::endl;
        file << kura.getPosition().x << " " << kura.getPosition().y << std::endl;
        file.close();
    } else {
        std::cerr << "Nie można otworzyć pliku do zapisu pozycji zwierząt." << std::endl;
    }
}

void Hodowla::loadAnimalPositions() {
    std::ifstream file("animal_positions.txt");
    float x, y;
    if (file.is_open()) {
        if (file >> x >> y) {
            krowa.setPosition(x, y);
        }
        if (file >> x >> y) {
            swinia.setPosition(x, y);
        }
         if (file >> x >> y) {
            kura.setPosition(x, y);
        }
        file.close();
    } else {
        std::cerr << "Nie można otworzyć pliku do wczytania pozycji zwierząt." << std::endl;
        // Ustaw domyślne pozycje, jeśli plik nie istnieje
        krowa.setPosition(initialPositionKrowa);
        swinia.setPosition(initialPositionSwinia);
        kura.setPosition(initialPositionKura);
    }
}




void Hodowla::updateCowMovementSwinia() {
    if (isSwiniaAlive) {
    static sf::Clock movementClocks; 
    static sf::Clock stopClock; 
                static float vx = 1;
     static float vy = 0;
      static float GRAVITY = 0.002;
    static bool isMoving = true; 
    static bool isStopped = false; 
    static const float moveTime = 3.f; 
    static const float stopTime = 3.f; 

    if (isMoving) {
        // Krowa się porusza
        sf::Vector2f velocity(vx, vy);
        swinia.move(velocity);

        if (movementClocks.getElapsedTime().asSeconds() >= moveTime) {
            isMoving = false;
            isStopped = true;
            vx = -vx; // Zmiana kierunku na przeciwny
            movementClocks.restart();
            stopClock.restart();
        }
    } else if (isStopped) {
        // Krowa zatrzymuje się
        if (stopClock.getElapsedTime().asSeconds() >= stopTime) {
            isStopped = false;
            isMoving = true;
            movementClocks.restart();
        }
    }

    if (vx < 0) {
        if (!swiniazdj.loadFromFile("hodowlazdj/swinka1.png")) {
            std::cerr << "Błąd podczas wczytywania." << std::endl;
        }
        swinia.setTexture(swiniazdj);
    } else {
        if (!swiniazdj.loadFromFile("hodowlazdj/swinka2.png")) {
            std::cerr << "Błąd podczas wczytywania." << std::endl;
        }
        swinia.setTexture(swiniazdj);
    }
}
}

void Hodowla::deadanimals()
{
    if (timerBar.isTimeUp()) {
        swinia.setTexture(swiniaEndTexture);
        isSwiniaAlive = false;
        swinia.setPosition(50.f,500.f);
         // Zmiana tekstury jeśli czas minął
    }

    if (timerBarkrowa.isTimeUp()) {
        krowa.setTexture(krowaEndTexture);
        isKrowaAlive = false; 
        krowa.setPosition(460.f,500.f);// Podobnie dla krowy
    }

    if (timerBarkura.isTimeUp()) {
        kura.setTexture(kuraEndTexture);
        isKuraAlive = false;
        kura.setPosition(890.f,500.f); // I dla kury
    }

}
void Hodowla::run()
{
    loadTimeFromFile();
    loadAnimalPositions();
renderTopasek();
    while (window.isOpen()) {
                czas = time(nullptr);
        czas_info = localtime(&czas);
        handleEvents();
        render();

    }
    //saveAnimalPositions();
}

void Hodowla::switchplace(){
            std::ofstream wypiszFile("wypisz_values.txt");
    if (wypiszFile.is_open()) {
        for (char znak : ReadSigns) {
            wypiszFile << znak << " ";
        }
        wypiszFile.close();
    }
    std::ofstream letterFile("letter_values.txt");
    if (letterFile.is_open()) {
        for (int value : Readvalues) {
            letterFile << value << " ";
        }
        letterFile.close();
    }
}

void Hodowla::render()
{
        window.clear();
        window.draw(background);
        exit.handleMouseInteraction();
        exit.draw();
        window.draw(pasek);
        window.draw(skrzynka);
        addToPasek();
        if(openwerehouse){
         Openall openall(window,ReadSigns,Readvalues);
         openall.drawtank();
        openall.addsToPasek();
        }

        addstorage();
if (ziarenko.getScale() != targetSize) {
        ziarenko.setScale(targetSize);
    }
        dodajzwierzeta();
         std::ifstream zlotowkiFile("zlotowki_value.txt");
        zlotowkiText.setString(std::to_string(zlotowkiValue));
        window.draw(zlotowkiText);
        window.draw(plot);
              updateCowMovementKrowa();
              updateCowMovementSwinia();
              updateCowMovementKura();
              deadanimals();
                window.draw(krowa);
                window.draw(swinia);
                window.draw(kura);
                
//std::cout<<Readvalues[0]<<std::endl;
timerBar.update();
    timerBar.draw(window);
    timerBarkrowa.update();
    timerBarkrowa.draw(window);
    timerBarkura.update();
    timerBarkura.draw(window);


        window.display();
}

void Hodowla::savetimeall() {

//std::time_t currentTime = std::time(nullptr);

    std::ofstream timeFile("hodowlazdj/czaszamknieciahodowla.txt");
    if (timeFile.is_open()) {

        timeFile <<  asctime(czas_info) << std::endl;
        timeFile.close();
    } else {
        std::cerr << "Unable to open the file to save time!" << std::endl;
    }
}

void Hodowla::saveTimeToFile() {
    std::ofstream file("hodowlazdj/czaszycia.txt");
    if (!file.is_open()) {
        std::cerr << "Nie można otworzyć pliku do zapisu czasu." << std::endl;
        return;
    }

    float remainingTimeSwinia = timerBar.getRemainingTime();
    float remainingTimeKrowa = timerBarkrowa.getRemainingTime();
    float remainingTimeKura = timerBarkura.getRemainingTime();

    file << remainingTimeSwinia << " " << remainingTimeKrowa << " " << remainingTimeKura;
    file.close();
}
void Hodowla::loadTimeFromFile() {
    std::ifstream file("saved_time.txt");
    if (!file.is_open()) {
        std::cerr << "Nie można otworzyć pliku do odczytu czasu." << std::endl;
        czasswinia = 20.0f;
        czaskrowa = 60.0f;
        czaskura = 80.0f;
        return;
    }

    file >> czasswinia >> czaskrowa >> czaskura;
    file.close();
}
void Hodowla::switchTofarm() {
    savetimeall();
    switchplace();
    saveTimeToFile();
    Game game(window);
    game.run();
    
}