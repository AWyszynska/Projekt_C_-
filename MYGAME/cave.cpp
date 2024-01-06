
#include "cave.h" 



Cave::Cave(sf::RenderWindow& window) : window(window),
exit(window, sf::Vector2f(50, 50), sf::Vector2f(100, 100)),
zlotowkiFile("zlotowki_value.txt"),imagePaths({"kopalnia/skala1.png","kopalnia/skala2.png"
,"kopalnia/skala3.png","kopalnia/skala4.png","kopalnia/skala5.png","kopalnia/skala6.png"}),
gen(rd()), dis(0, imagePaths.size() - 1){
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

if (!backgroundTexture.loadFromFile("kopalnia/kopalnia.png")) {
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
}

void Cave::renderTopasek(){
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
void Cave::addstorage(){
    if (!pointsphoto.loadFromFile("aazdj/kropki.png"))
    {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
    points.setTexture(pointsphoto);
    points.setPosition(830.0f, 725.0f);
    points.setScale(0.4f, 0.4f);
    window.draw(points);


    
        if (!skala1zdj.loadFromFile("kopalnia/skala1.png"))
    {
        std::cerr << "Błąd podczas wczytywania tła." << std::endl;
    }
    //skala1.setTexture(skala1zdj);
    //skala1.setPosition(300.0f, 300.0f);
    //skala1.setScale(0.5f, 0.5f);

}


void Cave::renderskala() {
    if (isRightMouseDown) {
        elapsedskala = clockskala.getElapsedTime();
        if (elapsedskala.asSeconds() <= 5.0f) {
            if (elapsedskala.asSeconds() >= 1.25f * (scaleSteps + 1)) {
                scaleFactorX += 0.25f;
                skala1.setScale(scaleFactorX, scaleFactorX);
                scaleSteps++;
            }
        
        } 
else {
           
            skala1.setScale(0, 0); 
            scaleSteps = 0;
            if(elapsedskala.asSeconds() <= 5.01f){
            genere_to_pasek();
            }
            

        }
    } //else {
        // Zresetuj stan wzrostu po zwolnieniu przycisku myszy
        //scale = 0.0f;
       // scaleSteps = 0;
        //skala1.setScale(scale, scale);
   // }
}

void Cave::genere_to_pasek(){
   randomPercent = std::rand() % 10001;
    float FloatRandom = randomPercent/100;
    if(FloatRandom <= 50){
        //ReadSigns.push_back('I');
         char znak = 'I';
bool znaleziono = false;
        for(int j = 0;j < ReadSigns.size(); j++){
            if(ReadSigns[j] == znak){
                
                Readvalues[j] += 1;
                znaleziono = true;
                
                break;
            }
        }
            if(!znaleziono){
                
                ReadSigns.push_back('I');
                Readvalues.push_back(0);
                for(int j = 0;j < ReadSigns.size(); j++){
                    if(ReadSigns[j] == 'I'){
                        Readvalues[j] += 1;
                        break;
                    }
                }
        
    }
    }
    else if(FloatRandom > 50 && FloatRandom <= 90){
        //ReadSigns.push_back('R');
         char znak = 'R';
bool znaleziono = false;
        for(int j = 0;j < ReadSigns.size(); j++){
            if(ReadSigns[j] == znak){
                
                Readvalues[j] += 1;
                znaleziono = true;
                
                break;
            }
        }
            if(!znaleziono){
                
                ReadSigns.push_back('R');
                Readvalues.push_back(0);
                for(int j = 0;j < ReadSigns.size(); j++){
                    if(ReadSigns[j] == 'R'){
                        Readvalues[j] += 1;
                        break;
                    }
                }
        
    }
    }
    else if(FloatRandom > 90 && FloatRandom <= 90.90)
    {
        //ReadSigns.push_back('L');
         char znak = 'D';
bool znaleziono = false;
        for(int j = 0;j < ReadSigns.size(); j++){
            if(ReadSigns[j] == znak){
                
                Readvalues[j] += 1;
                znaleziono = true;
                
                break;
            }
        }
            if(!znaleziono){
                
                ReadSigns.push_back('D');
                Readvalues.push_back(0);
                for(int j = 0;j < ReadSigns.size(); j++){
                    if(ReadSigns[j] == 'D'){
                        Readvalues[j] += 1;
                        break;
                    }
                }
        
    }
    }
    else{
        //ReadSigns.push_back('D');
         char znak = 'L';
bool znaleziono = false;
        for(int j = 0;j < ReadSigns.size(); j++){
            if(ReadSigns[j] == znak){
                
                Readvalues[j] += 1;
                znaleziono = true;
                
                break;
            }
        }
            if(!znaleziono){
                
                ReadSigns.push_back('L');
                Readvalues.push_back(0);
                for(int j = 0;j < ReadSigns.size(); j++){
                    if(ReadSigns[j] == 'L'){
                        Readvalues[j] += 1;
                        break;
                    }
                }
        
    }
    }
}


void Cave::addToPasek(){
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
                sf::Sprite sprite(obraz1);
                sprite.setPosition(position,700); 
                sprite.setScale(0.15f, 0.15f);
                window.draw(sprite);
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



void Cave::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } 
        
        
else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
    isShowing = true;
    int randomX = rand() % 1001+100;  
    int randomY = rand() % 601;  
    int randomRotation = rand() % 181; 
int randomScalesX = rand() % 120+50;
    skala1.setRotation(static_cast<float>(randomRotation));
    skala1.setPosition(static_cast<float>(randomX), static_cast<float>(randomY));
    int randomIndex = dis(gen) % 6;
         for (const auto& path : imagePaths) {
        sf::Texture texture;
        if (!texture.loadFromFile(path)) {
            std::cerr << "Błąd podczas wczytywania tła." << std::endl;
        }
        texturespath.push_back(texture);
    }
    skala1.setTexture(texturespath[randomIndex]);
    sf::FloatRect bounds = skala1.getLocalBounds();
    scaleFactorX = randomScalesX / bounds.width; 
    skala1.setScale(scaleFactorX, scaleFactorX);
    std::cout<<randomIndex<<std::endl;

} 
        
        else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            sf::Vector2f mousePos = window.mapPixelToCoords(mousePosition);
if (skala1.getGlobalBounds().contains(mousePos)) {
                    isRightMouseDown = true;
                    elapsedskala = clockskala.restart();
                }

            }
        } else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
  

            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            sf::Vector2f mousePos = window.mapPixelToCoords(mousePosition);

   sf::Vector2f mousePosFloat; 

mousePosFloat = window.mapPixelToCoords(mousePosition);
sf::Vector2<int> mousePosInt(static_cast<int>(mousePosFloat.x), static_cast<int>(mousePosFloat.y));


            if (skala1.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) || window.getViewport(window.getView()).contains(mousePosInt)) {
                clockskala.restart();
                isRightMouseDown = !isRightMouseDown;
                clockskala.restart(); 
               
            }
            if (exit.isHoveredButton()) {
                switchTofarm();
            } else if (points.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                openwerehouse = !openwerehouse;
            }
        }
    }
}



void Cave::run()
{
renderTopasek();
    while (window.isOpen()) {
        handleEvents();
        render();
        renderskala();
       
    }
}

void Cave::switchplace(){
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

void Cave::render()
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
        if(genereTopasek){
           genere_to_pasek();
            genereTopasek = false;
        }
        addstorage();
        if(isShowing && stop){
            window.draw(skala1);
            
        }
        std::cout << elapsedskala.asSeconds() << std::endl;
         std::ifstream zlotowkiFile("zlotowki_value.txt");
        zlotowkiText.setString(std::to_string(zlotowkiValue));
        window.draw(zlotowkiText);
        
        window.display();
}

void Cave::switchTofarm() {
    switchplace();
    Game game(window);
    game.run();
    
}








