example-nrf5-gatt-mrt
============================

This is an example project demonstrating the use the the ``mrt-ble`` tool to create a gatt server on the NRF5 platform. ``mrt`` refers to the fact that the project uses the ``MrT`` framework.


.. note: while this can be done in any IDE you prefer, some of notes in the walkthrough assume the project is opened in VS Code.

Building
--------

.. note:: This project contains a devcontainer configuration file which will build a container with all of the build dependencies.

.. code:: bash 
    
    make

Flashing
--------

If building on a linux host (or in the devcontainer with access to host devices) you can flash with make: 

.. code:: bash 
    make flash_softdevice
    make flash


If you are using a windows machine as host, you can flash using the NRF-Connect programmer app.

Update Profile
--------------

The gatt profile can be changed by editing the example_profile.yml file, and then using mrt-ble: 

.. code:: bash 

    mrt-ble -i example_profile.yml -o src/gatt/ -d .

For convenience this has been added as a target to the makefile 

.. code:: bash 

    make update


