# robot
Detta är koden för projektgrupp 8. Målet var att bygga en fungerande robot som kunde plocka upp bollar och kasta
över dem över en vajer.


# struktur
Det kommer finnas två stycken arduinos, en som är ansvarig över drift i motorerna och den andra är ansvarig över
sensorerna. Dessa kommer kommunicera med varandra genom att skicka korta preambles, SFD, Datatyp kanske en checksum sen
till datan, och datan vilket består av någon specifik kod som för en state eller information som arduinos ska 
förhålla sig till. Sen kommer den andra skicka en ACK. De kommer även använda sig av interups vid dataskicknig.

# Motor arduino
Till denna ska motorerna sitta, denna arduino ska även vara hjärnan och tar alla större beslut av roboten som vart
den ska åka.

# Sensor arduino
Till denna kommer alla sensorer sitta och ska förmedla viktig information till motor arduino så att denna kan ta
rätt beslut. Som

