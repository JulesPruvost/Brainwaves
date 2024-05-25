**#Brainwaves**

Welkom bij ons project, waarin we de Emotiv Cortex API integreren voor een eindwerk in het 6de jaar industriële wetenschappen. Deze code is geschreven door Jarne Qualy en Jules Pruvost. Het project maakt gebruik van de Emotiv Cortex API om hersenactiviteit te meten en deze data te gebruiken om een klein autootje aan te sturen via een Arduino.

**##Bestanden**

**###Connect.py**

Dit script start de connectie met de Emotiv Cortex API en haalt de noodzakelijke accountgegevens (zoals de client token en client secret) op uit pass.txt.

**###pass.txt**

Dit bestand bevat de client token, client secret en de profile name. Zorg ervoor dat dit bestand goed beveiligd is, omdat het gevoelige informatie bevat.

**cortex.py**

Dit script haalt data op van de Emotiv server via API requests. Het maakt verbinding met de Cortex API en verzamelt de hersenactiviteitsdata die we nodig hebben voor ons project.

**headset.py**

Dit script bevat extra methodes voor de opstart van het programma en bevat logica voor het versturen van data via een seriële monitor naar de Arduino.

**Main.ino**

Dit is het Arduino-script dat het kleine autootje aanstuurt op basis van de ontvangen data. Het script ontvangt signalen en stuurt vervolgens de motoren van het autootje aan.

**Overzicht**

Ons project is ontworpen om hersenactiviteit te meten en te vertalen naar bewegingen van een klein autootje. Dit project toont de mogelijkheden van hersen-computer interfaces en biedt een praktische toepassing van de Emotiv Cortex API.

We hopen dat ons project anderen inspireert om verder te verkennen wat mogelijk is met hersen-computer interfaces en de Cortex API.

Voor meer informatie over de Cortex API, zie de officiële documentatie. (https://emotiv.gitbook.io/cortex-api)
