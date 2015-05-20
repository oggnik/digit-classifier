# digit-classifier

To build, change to the src director and type `make`.  This will build the classifier executable.

To train the neural network, run the program with `./classifier`.  After each training pass, the network will be saved to `current_network.dat`.

To load a previously trained network, run the program with: `./classifier -f /path/to/network/file`.

A pretrained network file which has about a 7% error rate is located in the trained\_networks folder.
