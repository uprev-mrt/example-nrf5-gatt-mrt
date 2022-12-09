example-nrf5-gatt-standalone
============================

This is an example project demonstrating the use the the ``mrt-ble`` tool to create a gatt server on the NRF5 platform. ``Standalone`` refers to the fact that the project does not actually use the ``MrT`` framework. The ``mrt-ble`` utility just pulls the necessary adapter files into the project. 


.. note: while this can be done in any IDE you prefer, some of notes in the walkthrough assume the project is opened in VS Code.

Step 0: Starting Point
----------------------

The starting point of this project is the ``ble_app_template`` from the `NRF SDK 17.1.0. <https://developer.nordicsemi.com/nRF5_SDK/nRF5_SDK_v17.x.x/nRF5_SDK_17.1.0_ddde560.zip>`_. 

Step 1: Removing old ble code 
-----------------------------

Because we are starting with the template example from the SDK, everything we need to replace is tagged with ``YOUR_JOB:``. 


Step 2: Specify the Gatt Profile
--------------------------------

``mrt-ble`` uses yaml files to describe gatt profiles and generate code. The easiest way to get started is to generate the example template 

.. code:: bash 

    mrt-ble -t example_profile 

This will generate `example_profile.yml` which contains an example profile for a battery powered sprinkler control system. The file has comments explaining the various features but more detailed information can be found in the `MrT Docs <https://mrt.readthedocs.io/en/latest/pages/mrtutils/mrt-ble.html#step-1-define-the-profile>`_
