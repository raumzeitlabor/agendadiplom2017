# LineBot

## Allgemeine Tipps

In einem sehr hellen Raum hat der Bot Schwierigkeiten, die Linien zu finden.
Deshalb etwas abdunkeln. Du kannst auch eine hellere LED einlöten. Außerdem
müssen die gemalten Linien recht breit sein. Also einen dicken Edding nehmen,
oder ein dunkles Klebeband. Der Bot hat keine Reifen, nur ein kleines Stück
Schrumpfschlauch auf den Achsen. Falls der sich gelöst hat, kommt der Bot nicht
mehr richtig um die Kurve. Dann einfach noch ein bisschen den Schrumpfschlauch
erhitzen, z.B. mit einem Feuerzeug.

## Bauanleitung

> Sicherheitshinweise
> 
> Lötzinn enthält Blei; das ist nicht gesund, wenn man es verschluckt. Wasch
> Dir deshalb nach dem Löten gründlich die Hände. Während des Arbeitens mit dem
> Lötkolben solltest Du nicht mit Lebensmitteln hantieren oder essen.
> 
> Der Lötkolben hat an seiner Spitze eine Temperatur von ca. 300 bis 350°C,
> genug um bestimmte Metalle zu schmelzen. Gib deshalb besonders Acht, Dich und
> andere nicht zu verletzen und stelle den Lötkolben immer in die Halterung,
> wenn Du ihn gerade nicht benötigst.
> 
> Halte überstehende Drahtenden fest, wenn Du sie abzwickst. So kannst Du
> vermeiden, dass die Teile wegspringen und Dich oder jemanden in Deiner
> Umgebung treffen.

Eine Platine hat normalerweise Symbole aufgedruckt, welche Bauteile man an
einer bestimmten Stelle einsetzen muss. 
Widerstände sind mit Rechtecken dargestellt und einem Wert, der mit R beginnt.
Zum Beispiel bedeutet R3: an diese Stelle gehört der Widerstand (engl.
Resistor) Nummer drei.

Die Abstände der einzelnen Kontakte haben meistens einen festen Wert, der sich
am amerikanischen Einheitensystem orientiert. Bauteile, z.B. Kondensatoren,
Widerstände, passen genau in die Platine hinein, wenn Du die Drähte mit einer
Biege-Lehre gleichmäßig umbiegst.
Damit die Teile nicht wieder herausfallen, wenn Du die Platine zum Löten
umdrehst, kannst Du die Beinchen ein wenig auseinanderbiegen.

Das Löten klappt prima, wenn Du Dich an eine einfache Reihenfolge hälst:
Lötkolben dran, Lötzinn dran, Lötzinn weg, Lötkolben weg.
Wenn Du alles richtig gemacht hast, ist das Lötzinn geschmolzen und hat um die
Kontaktstelle einen etwa kegelförmigen Hügel gebildet.

Als erstes löten wir den Elektrolytkondensator C1 auf der Unterseite der
Platine ein.
Achte darauf, das Bauteil richtig herum einzusetzen. Auf der Seite mit dem
Pluspol ist eine Kerbe, die auch auf der Platine eingezeichnet ist.
Ein Elektrolytkondensator wirkt wie eine kleine Batterie. In unserer Schaltung
ist er dazu da, Spannungsschwankungen abzufangen, wenn die Motoren anlaufen.

Nun kommt der Sockel für den Microcontroller. Er hat an einer Seite eine Kerbe,
damit man ihn richtig herum einbaut. Beginne das Löten mit einer Ecke.
Kontolliere dann, ob das Bauteil gut sitzt. Dann kommt die diagonal
gegenüberliegende Ecke dran. Wenn der Sockel fest und gerade auf der Platine
sitzt, kannst Du auch die restlichen Kontakte festlöten.
Stecke dann den Microcontroller auf den Sockel. Eine Ecke ist mit einem Punkt
markiert. Die muss dort hin, wo auf der Platine eine 1 steht.
Der Microcontroller ist ein ATTiny85. Er ist das Gehirn unseres Roboters. Dort
kommen die Messwerte aus den Sensoren an und die Motoren bekommen von dort ihre
Steuersignale.

Jetzt löten wir alle fünf Widerstände fest. Die Richtung ist bei einem
Widerstand nicht wichtig aber der Wert muss stimmen. Jeder Widerstand hat einen
Code aus farbigen Ringen aufgedruckt. Achte darauf, dass Du die Widerstände in
Deinem Roboter-Bausatz nicht durcheinander bringst. Wenn Du Dir nicht sicher
bist, kannst Du den Wert des Widerstandes mit dem Multimeter nachmessen.
Widerstände sind zum Beispiel dazu da, den Strom in der Schaltung zu begrenzen,
damit andere Bauteile nicht kaputt gehen.

Die zwei kleinen Dioden sind als nächstes dran. Diesmal ist es wichtig, sie
richtig herum einzubauen. Dafür haben sie auf einer Seite einen schwarzen
Strich. In unserer Schaltung sind sie dafür zuständig, die Spannung der Motoren
abzufangen, die den Rest der Schaltung durcheinanderbringen würde.

Nun kommen die Transistoren dran. Sie haben eine flache und eine runde Seite,
damit man weiß, wie man sie einbauen muss. Die Beinchen der Transistoren sind
sehr dicht zusammen. Gib darauf acht, dass Du die Kontakte auf der Platine
nicht mit zu viel Lötzinn verbindest.
Transistoren funktionieren wie eine Schleuse: Wenn an der Basis (hier in der
Mitte) ein kleiner Steuerstrom anliegt, dann öffnen sie die Verbindung und
lassen den Strom durch. Wir brauchen Sie zum Ansteuern der Motoren.

Der Schalter hat drei Kontakte in der Mitte, die Du anlöten musst. Die beiden
Pfosten helfen, dass der Schalter besser auf der Platine hält und Du musst Sie
nicht anlöten.
Mit dem Schalter kannst Du den Bot ausschalten, wenn Du ihn gerade nicht auf
Liniensuche schicken willst.

Die Leuchtdiode (LED - Light Emitting Diode) kommt auf die Unterseite der
Platine. Sie funktioniert nur, wenn Du sie richtig herum einbaust. Die
abgeflachte Seite der LED ist eingezeichnet. Jetzt wird es ein bisschen
komplizierter. Die beiden Fototransistoren haben auch eine flache Seite. Sie
werden aber nicht direkt eingesetzt, sondern mit einer Halterung, die genau
darüber passt. Achte darauf, dass die Fototransistoren richtig herum sind und
drücke sie ganz in das Gehäuse hinein, bevor Du alles anlötest. Die Beinchen
der Transistoren kannst Du abzwicken. Aber wirf sie nicht weg, wir brauchen sie
im nächsten Schritt.
Die Fototransistoren sind der Sensor unseres Roboters. Sie lassen mehr Strom
durch, wenn mehr Licht einfällt. Das Licht kommt in diesem Fall von der LED und
wird dann von der Oberfläche des Tisches reflektiert. Eine dunkle Linie
reflektiert nicht so viel Licht und wird deshalb von den Sensoren erkannt.

Als Antrieb für unseren Roboter dienen zwei kleine Elektromotoren. Zur Montage
schiebst Du sie in die Halterung aus Kunststoff, bedruckte Seite in Richtung
Schlitz. Die Kontaktbeinchen kommen durch die Ösen der Halterung und werden
direkt am Motor angelötet. Biege die Kontakte so, dass sie senkrecht zur
Bodenfläche stehen und löte die Motoren auf der Platine fest.
Die Motoren sind sehr klein und haben nur ein geringes Drehmoment. Deshalb
bekommt unser Bot keine großen Reifen.

Als letztes wird die Batteriehalterung angelötet. Wenn Du nun die Batterien
einsetzt und den Schalter anstellst sollte der Bot losfahren. Viel Spaß!

