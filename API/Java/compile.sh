rm -f *.class
javac -Xlint DatabaseGenerator.java
java DatabaseGenerator
javac -Xlint ThermoDatabase.java TransportDatabase.java OmegaDatabase.java Asali.java Example.java

