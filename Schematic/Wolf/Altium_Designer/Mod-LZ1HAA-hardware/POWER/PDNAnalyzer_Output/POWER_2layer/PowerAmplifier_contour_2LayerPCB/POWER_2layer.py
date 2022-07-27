designFile = "D:/Altera_projects/UA3REO-DDC-Transceiver-hristo/Scheme/ALTIUM_DESIGNER/POWER/PDNAnalyzer_Output/POWER_2layer/odb.tgz"

powerNets = ["+13.8V_IN", "PA_CUR_P", "PA_CUR_N"]

groundNets = ["GND"]

excitation = [
{
"id": "0",
"type": "source",
"power_pins": [ ("J2", "1"), ("J2", "2") ],
"ground_pins": [ ("J2", "3"), ("J2", "4") ],
"voltage": 13.8,
"Rpin": 0,
}
,
{
"id": "1",
"type": "load",
"power_pins": [ ("J1", "1") ],
"ground_pins": [ ("J1", "2") ],
"current": 20,
"Rpin": 0.005,
}
]


voltage_regulators = [
{
"id": "2",
"type": "linear",

"in": [ ("U1", "8") ],
"out": [ ("U1", "3"), ("U1", "2"), ("U1", "1") ],
"ref": [],

"v2": 0,
"i1": 0,
"Ro": 1E-06,
"Rpin": 0.003,
}
,
{
"id": "3",
"type": "linear",

"in": [ ("R1", "1") ],
"out": [ ("R1", "2") ],
"ref": [],

"v2": 0,
"i1": 0,
"Ro": 1E-06,
"Rpin": 0.001,
}
]


# Resistors / Inductors

passives = []


# Material Properties:

tech = [

        {'name': 'TOP_SOLDER', 'DielectricConstant': 3.5, 'Thickness': 1.016E-05},
        {'name': 'TOP_LAYER', 'Conductivity': 47000000, 'Thickness': 3.556E-05},
        {'name': 'SUBSTRATE-1', 'DielectricConstant': 4.8, 'Thickness': 0.0015},
        {'name': 'BOTTOM_LAYER', 'Conductivity': 47000000, 'Thickness': 3.556E-05},
        {'name': 'BOTTOM_SOLDER', 'DielectricConstant': 3.5, 'Thickness': 1.016E-05}

       ]

special_settings = {'removecutoutsize' : 7.8 }


plating_thickness = 0.7
finished_hole_diameters = False
