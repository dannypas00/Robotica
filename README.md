# Robotica
Robotica project NHL-Stenden Periode 4 2020

Programmeren in een WeBots Controller
==
# Folder structuur:
In de folder bungie_demo staan alle files die behoren tot de WeBots omgeving. Hieronder valt bijvoorbeel de simulatie wereld zelf. 
De scene: Robotica\bungie_demo\worlds\moon.wbt
Deze file is toegevoegd aan de .gitignore om te voorkomen dat de scene wordt overschreven. Indien je hier iets in aan past gelieve melden en overleggen voor je pushed.
GitHub is niet gemaakt om dit soort files samen te voegen en dit gaat dan ook fout.

# Scene management:
In WeBots zelf hoef je geen dingen aan te passen in de scene, mis je functionaliteit? Overleg met het team van aansturing om dit erin te zetten.

# Code:
In het project staan veel folders, maar als programmeur heb je alleen te maken met de controller.
Deze vind je hier: Robotica\bungie_demo\controllers\BungieController
In deze map staan de classes van de aansturing, vision en machine intelligence.

Robotica\bungie_demo\controllers\BungieController\BungieController.cpp is de main class, test hiermee je code. In deze class staat de main functie.
Deze manier van een main class is een vereiste van WeBots, deze class linked namelijk de code aan de scene.

Om je classes toe te voegen moet jij je *broncode* verplaatsen naar dit mapje. Let hierbij wel op dat de code nog compiled.
Hier kunnen verschillende dingen mis gaan, zoals het gebruik van Visual Studio specifieke functionaliteit of WeBots specifieke code.

# Make:
Je hoeft niks toe te voegen aan de makefile. Jouwn classes in andere folders worden ook automatisch meegecompiled.


Om te testen of je code werkt maak een simpele call in main en zorg voor visual feedback voor jezelf.

Heb je vragen over de setup of de werking van één van de veranderingen vraag gerust het aansturing team.


