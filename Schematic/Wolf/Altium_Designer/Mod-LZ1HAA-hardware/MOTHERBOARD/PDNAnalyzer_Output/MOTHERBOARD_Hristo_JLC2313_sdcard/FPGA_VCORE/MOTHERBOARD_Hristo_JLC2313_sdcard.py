designFile = "D:/Altera_projects/UA3REO-DDC-Transceiver-hristo/Scheme/ALTIUM_DESIGNER/MOTHERBOARD/PDNAnalyzer_Output/MOTHERBOARD_Hristo_JLC2313_sdcard/odb.tgz"

powerNets = ["+1V2"]

groundNets = ["GND"]

excitation = [
{
"id": "0",
"type": "source",
"power_pins": [ ("U16", "4") ],
"ground_pins": [ ("U16", "1") ],
"voltage": 1.2,
"Rpin": 0,
}
,
{
"id": "1",
"type": "load",
"power_pins": [ ("U11", "138"), ("U11", "134"), ("U11", "124"), ("U11", "116"), ("U11", "109"), ("U11", "102"), ("U11", "84"), ("U11", "78"), ("U11", "73"), ("U11", "70"), ("U11", "61"), ("U11", "45"), ("U11", "38"), ("U11", "37"), ("U11", "34"), ("U11", "29"), ("U11", "5"), ("U11", "1") ],
"ground_pins": [ ("U11", "pdna_pin_145_1"), ("U11", "pdna_pin_145_2"), ("U11", "140"), ("U11", "131"), ("U11", "123"), ("U11", "118"), ("U11", "108"), ("U11", "97"), ("U11", "95"), ("U11", "94"), ("U11", "82"), ("U11", "79"), ("U11", "74"), ("U11", "63"), ("U11", "57"), ("U11", "48"), ("U11", "41"), ("U11", "36"), ("U11", "27"), ("U11", "22"), ("U11", "19"), ("U11", "4"), ("U11", "2") ],
"current": 0.5,
"Rpin": 4.0390243902439,
}
]


voltage_regulators = []


# Resistors / Inductors

passives = []


# Material Properties:

tech = [

        {'name': 'TOP_SOLDER', 'DielectricConstant': 3.8, 'Thickness': 2.032E-05},
        {'name': 'TOP_LAYER', 'Conductivity': 47000000, 'Thickness': 3.5E-05},
        {'name': 'SUBSTRATE-1', 'DielectricConstant': 4.05, 'Thickness': 8.89E-05},
        {'name': 'GND', 'Conductivity': 47000000, 'Thickness': 1.75E-05},
        {'name': 'SUBSTRATE-2', 'DielectricConstant': 4.3, 'Thickness': 0.001265},
        {'name': 'POWER', 'Conductivity': 47000000, 'Thickness': 1.75E-05},
        {'name': 'SUBSTRATE-3', 'DielectricConstant': 4.05, 'Thickness': 8.89E-05},
        {'name': 'BOTTOM_LAYER', 'Conductivity': 47000000, 'Thickness': 3.5E-05},
        {'name': 'BOTTOM_SOLDER', 'DielectricConstant': 3.8, 'Thickness': 2.032E-05}

       ]

special_settings = {'removecutoutsize' : 7.8 }


plating_thickness = 0.7
finished_hole_diameters = False
