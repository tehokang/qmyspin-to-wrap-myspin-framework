/* ---------------------------------------------------------------------------------------------------------------
   VEHICLE DATA KEY definition file
   (C) Bosch SoftTec GmbH 2015-2017

   Generated file - version 1.10.0 as of 2017-05-31

   Notes:
   - JSON examples for default value strings are not given.
        Numerical:
           { "value": <number> } for numerical values; <number> may consist of sign and digits
        Boolean:
           { "value": true }
           { "value": false }
        String:
           { "value": "this is the value string" }
   - The standard error value strings are
           { "status": "not supported" }
           { "status": "unknown" }
           { "status": "invalid" }
   - If there are minimum or maximum values defined this is indicated.
*/

#ifndef MYSPIN_VEHICLE_DATA_KEYS_BSOT_H_
#define MYSPIN_VEHICLE_DATA_KEYS_BSOT_H_

#ifdef  __cplusplus
extern "C" {
#endif

	/*
	 * VEHICLE_DATA_KEY_AMBIENT_TEMP
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: -60.00
	 *      maximum value: 100.00
	 *      unit         : deg Celsius
	 * 
	 * Description:
	 *     Measured ambient temperature
	 *     value   temperature
	 *     Note:
	 *     Values are expected in degrees, 1/10 degrees or 1/4 degrees; i.e. -8, 32.0, 23.4 or 16.25 are valid, -12.46 not.
	 */
#define VEHICLE_DATA_KEY_AMBIENT_TEMP  853173681u

	/*
	 * VEHICLE_DATA_KEY_BRAKE_PRESSURE
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0.0
	 *      maximum value: 99.0
	 *      unit         : bar
	 * 
	 * Description:
	 *     The signal informs about the pressure in the master cylinder.
	 *     value   pressure in bar; increments of 0.1bar possible
	 */
#define VEHICLE_DATA_KEY_BRAKE_PRESSURE  1036390343u

	/*
	 * VEHICLE_DATA_KEY_BLIND_SPOT_ASSISTANCE_LEFT_ALERT
	 * 
	 * JSON type: BOOLEAN
	 * 
	 * Description:
	 *     An object of interest has been detected within the alert zone on the left side of the vehicle and the driver should be alerted that there is an object present.
	 *     true    object present warning on
	 *     false   object present warning off
	 */
#define VEHICLE_DATA_KEY_BLIND_SPOT_ASSISTANCE_LEFT_ALERT  197124744u

	/*
	 * VEHICLE_DATA_KEY_BLIND_SPOT_ASSISTANCE_RIGHT_ALERT
	 * 
	 * JSON type: BOOLEAN
	 * 
	 * Description:
	 *     An object of interest has been detected within the alert zone on the right side of the vehicle and the driver should be alerted that there is an object present.
	 *     true    object present warning on
	 *     false   object present warning off
	 */
#define VEHICLE_DATA_KEY_BLIND_SPOT_ASSISTANCE_RIGHT_ALERT  1801498169u

	/*
	 * VEHICLE_DATA_KEY_ACTUAL_GEAR_POSITION
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 31
	 * 
	 * Description:
	 *     This is the gear position for the manual gearbox
	 *     0   Neutral
	 *     1   1st Gear
	 *     2   2nd Gear
	 *     3   3rd Gear
	 *     4   4th Gear
	 *     5   5th Gear
	 *     6   6th Gear
	 *     7   Reverse Gear
	 *     8   Undefined Gear
	 *     10 Indicator of Automatic Gearbox
	 *     11-31 Reserved by OEM
	 */
#define VEHICLE_DATA_KEY_ACTUAL_GEAR_POSITION  258945671u

	/*
	 * VEHICLE_DATA_KEY_DISTANCE_TO_EMPTY
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 9998
	 *      unit         : km
	 * 
	 * Description:
	 *     Trip computer range function displayed value in kilometres.
	 *     0-9998 Distance in km
	 */
#define VEHICLE_DATA_KEY_DISTANCE_TO_EMPTY  3025988756u

	/*
	 * VEHICLE_DATA_KEY_DOOR_STATUS
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 63
	 * 
	 * Description:
	 *     Door Status
	 *     => binary coded, 6bit
	 *     Bit 0 = LFD Status, 0 = open, 1 = closed 
	 *     Bit 1 = RFD Status, 0 = open, 1 = closed 
	 *     Bit 2 = LRD Status, 0 = open, 1 = closed 
	 *     Bit 3 = RRD Status, 0 = open, 1 = closed 
	 *     Bit 4 = TailgateStatus, 0 = open, 1 = closed 
	 *     Bit 5 = EngineHoodStatus, 0 = open, 1 = closed
	 */
#define VEHICLE_DATA_KEY_DOOR_STATUS  3685833586u

	/*
	 * VEHICLE_DATA_KEY_DSC_OFF_INDICATOR
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 3
	 * 
	 * Description:
	 *     Signal to control the DSC-Off indicator (usually lamp which indicates to the driver that the Dynamic Stability Control function has been switched off).
	 *     0   Indicator OFF continuously
	 *     1   Indicator ON continuously
	 *     2   Indicator flashing
	 *     3   Invalid
	 */
#define VEHICLE_DATA_KEY_DSC_OFF_INDICATOR  1887042915u

	/*
	 * VEHICLE_DATA_KEY_PARK_BRAKE_STATUS
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 3
	 * 
	 * Description:
	 *     Summary of the park brake mode.
	 *     0   Park Brake disengaged.
	 *     1   Park Brake engaged.
	 *     2-3 Reserved by OEM
	 */
#define VEHICLE_DATA_KEY_PARK_BRAKE_STATUS  197648257u

	/*
	 * VEHICLE_DATA_KEY_GEAR_LEVEL_POSITION
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 15
	 * 
	 * Description:
	 *     Gear lever position.
	 *     0   P (Park)
	 *     1   R (Reverse)
	 *     2   N (Neutral)
	 *     3   D (Drive)
	 *     4-15 Reserved by OEM
	 */
#define VEHICLE_DATA_KEY_GEAR_LEVEL_POSITION  49133454u

	/*
	 * VEHICLE_DATA_KEY_DISPLAY_ENGINE_SPEED
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 20000
	 *      unit         : rpm
	 * 
	 * Description:
	 *     Engine RPM to be displayed by HUD.
	 */
#define VEHICLE_DATA_KEY_DISPLAY_ENGINE_SPEED  2680898438u

	/*
	 * VEHICLE_DATA_KEY_DISPLAY_VEHICLE_SPEED
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 500
	 *      unit         : km/h
	 * 
	 * Description:
	 *     Vehicle speed
	 *     0-500   speed
	 */
#define VEHICLE_DATA_KEY_DISPLAY_VEHICLE_SPEED  2201960939u

	/*
	 * VEHICLE_DATA_KEY_LATERAL_ACCELERATION
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: -12.0
	 *      maximum value: 12.0
	 *      unit         : m/s^2
	 * 
	 * Description:
	 *     Value of lateral acceleration, positive in a right (clockwise) turn.
	 *     -12 .. 12 m/s^2; increments of 0.1 possible
	 */
#define VEHICLE_DATA_KEY_LATERAL_ACCELERATION  1072423361u

	/*
	 * VEHICLE_DATA_KEY_LOW_FUEL_LEVEL
	 * 
	 * JSON type: BOOLEAN
	 * 
	 * Description:
	 *     Low Fuel Warning TRUE/FALSE
	 *     false   Low Fuel Light Off (Fuel Level Ok)
	 *     true    Low Fuel Light On (Fuel Level Low)
	 */
#define VEHICLE_DATA_KEY_LOW_FUEL_LEVEL  673299829u

	/*
	 * VEHICLE_DATA_KEY_PEDAL_POSITION
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0.0
	 *      maximum value: 101.0
	 *      unit         : %
	 * 
	 * Description:
	 *     Driver demanded accelerator pedal position in %. 
	 *     0.0-100.0        0-100%; increment of 0.5% possible
	 *     101.5 reserved
	 *     101.0 Kickdown
	 */
#define VEHICLE_DATA_KEY_PEDAL_POSITION  3997030663u

	/*
	 * VEHICLE_DATA_KEY_ROOF_POSITION_STATUS
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 7
	 * 
	 * Description:
	 *     Indicates the current hood status.
	 *     0   Closed
	 *     1   Open
	 *     2   Closing
	 *     3   Opening
	 *     4   Stalled
	 *     5-7 Reserved by OEM
	 */
#define VEHICLE_DATA_KEY_ROOF_POSITION_STATUS  2407239283u

	/*
	 * VEHICLE_DATA_KEY_RUNNING_STANDBY
	 * 
	 * JSON type: BOOLEAN
	 * 
	 * Description:
	 *     Signal indicates whether the engine is in Eco Stop or not
	 *     false   Engine is NOT in Eco Stop
	 *     true    Engine is in Eco Stop
	 */
#define VEHICLE_DATA_KEY_RUNNING_STANDBY  3368814715u

	/*
	 * VEHICLE_DATA_KEY_STEERING_WHEEL_ANGLE
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: -780.0
	 *      maximum value: 780.0
	 *      unit         : degrees
	 * 
	 * Description:
	 *     This signal provides the a measurement of the steering wheel position. 
	 *     The angle is measured as referenced from a 0 degree straight-ahead position. - If the steering wheel is rotated clockwise, the measurement decreases. - If the steering wheel is rotated anti-clockwise, the measurement increases.
	 *     -780.0 ..780.0 degrees; increment of 0.1 degrees possible
	 */
#define VEHICLE_DATA_KEY_STEERING_WHEEL_ANGLE  1838688940u

	/*
	 * VEHICLE_DATA_KEY_TOW_BAR_LOAD
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: -100
	 *      maximum value: 1000
	 *      unit         : kg
	 * 
	 * Description:
	 *     Indicates the Z axis towbar load
	 *     -> see JLR-PCV-TEL(SWRS) Revision 14 for PAG-0626
	 */
#define VEHICLE_DATA_KEY_TOW_BAR_LOAD  1140267839u

	/*
	 * VEHICLE_DATA_KEY_TRANSFER_SHIFT_INDICATION
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 7
	 * 
	 * Description:
	 *     This signal is to prompt the driver to perform an upshift resp downshift.
	 *     0      No indication.
	 *     1      Upshift warning.
	 *     2      Downshift warning
	 *     3-7  Reserved by OEM
	 */
#define VEHICLE_DATA_KEY_TRANSFER_SHIFT_INDICATION  831410691u

	/*
	 * VEHICLE_DATA_KEY_TRAFFICSIGN_RECOGNITION_SPEED_LIMIT
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 500
	 *      unit         : km/h
	 * 
	 * Description:
	 *     Traffic Sign Recognition speed limit
	 *     0                  No recognition
	 *     1                  No speed limit
	 *     <value>    current speed limit
	 */
#define VEHICLE_DATA_KEY_TRAFFICSIGN_RECOGNITION_SPEED_LIMIT  1215065793u

	/*
	 * VEHICLE_DATA_KEY_TYRE_PRESSURE_FL
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 12000
	 *      unit         : hPa
	 * 
	 * Description:
	 *     Front left tyre pressure.
	 *     0-12000          tyre pressure in hPa
	 */
#define VEHICLE_DATA_KEY_TYRE_PRESSURE_FL  4078700541u

	/*
	 * VEHICLE_DATA_KEY_TYRE_PRESSURE_FR
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 12000
	 *      unit         : hPa
	 * 
	 * Description:
	 *     Front right tyre pressure.
	 *     0-12000          tyre pressure in hPa
	 */
#define VEHICLE_DATA_KEY_TYRE_PRESSURE_FR  3360914402u

	/*
	 * VEHICLE_DATA_KEY_TYRE_PRESSURE_RL
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 12000
	 *      unit         : hPa
	 * 
	 * Description:
	 *     Rear left tyre pressure.
	 *     0-12000          tyre pressure in hPa
	 */
#define VEHICLE_DATA_KEY_TYRE_PRESSURE_RL  528632749u

	/*
	 * VEHICLE_DATA_KEY_TYRE_PRESSURE_RR
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 12000
	 *      unit         : hPa
	 * 
	 * Description:
	 *     Rear right tyre pressure.
	 *     0-12000          tyre pressure in hPa
	 */
#define VEHICLE_DATA_KEY_TYRE_PRESSURE_RR  2161508317u

	/*
	 * VEHICLE_DATA_KEY_WADE_INCLINE_DISPLAY
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 3
	 * 
	 * Description:
	 *     The signal indicates whether the vehicle is level or on an incline nose up or nose down.
	 *        0: reserved 
	 *        1: vehicle level
	 *        2: vehicle level nose is up
	 *        3: vehicle level nose is down
	 */
#define VEHICLE_DATA_KEY_WADE_INCLINE_DISPLAY  2506049765u

	/*
	 * VEHICLE_DATA_KEY_WAD_MAX_DEPTH
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 60
	 *      unit         : m
	 * 
	 * Description:
	 *     This signal indicates the vehicle max water depth capability of the vehicle.
	 */
#define VEHICLE_DATA_KEY_WAD_MAX_DEPTH  4151969099u

	/*
	 * VEHICLE_DATA_KEY_WADE_MAX_SPEED
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 30
	 *      unit         : km/h
	 * 
	 * Description:
	 *     This signal indicates the vehicle max speed for wading.
	 */
#define VEHICLE_DATA_KEY_WADE_MAX_SPEED  2950727881u

	/*
	 * VEHICLE_DATA_KEY_WIPER_STATUS
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 7
	 * 
	 * Description:
	 *     Specifies the current operating status of the front wiper system.
	 *     0   Wipers Off
	 *     1   Intermittent Wipe
	 *     2   Normal (Slow) Continuous Wipe
	 *     3   Fast Continuous Wipe
	 *     4 .. 7 reserved by OEM
	 */
#define VEHICLE_DATA_KEY_WIPER_STATUS  483611491u

	/*
	 * VEHICLE_DATA_KEY_YAW_RATE
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: -100.0
	 *      maximum value: 100.0
	 *      unit         : degrees/second
	 * 
	 * Description:
	 *     This signal represents the yaw rate of the vehicle. The value of yaw rate is positive in a right (clockwise) turn.
	 *     -100 .. +100 Degrees/second; increments of 0.1 (or 0.2) degrees possible
	 */
#define VEHICLE_DATA_KEY_YAW_RATE  2432068873u

	/*
	 * VEHICLE_DATA_KEY_YAW_RATE_CORRELATION_STATUS
	 * 
	 * JSON type: BOOLEAN
	 * 
	 * Description:
	 *     Indicates whether a deviation has been detected between the expected Yaw Rate based on Steering Angle and Vehicle Speed and the measured Yaw Rate. This may occur for a number of reasons Understeer, oversteer, Vehicle path guided by ruts.
	 *     false   No Yaw Rate deviation
	 *     true   Yaw Rat deviation detected
	 */
#define VEHICLE_DATA_KEY_YAW_RATE_CORRELATION_STATUS  382511424u

	/*
	 * VEHICLE_DATA_KEY_VEHICLE_BRAND
	 * 
	 * JSON type: STRING
	 * 
	 * Description:
	 *     This is the name of the vehicle brand.
	 */
#define VEHICLE_DATA_KEY_VEHICLE_BRAND  3224792493u

	/*
	 * VEHICLE_DATA_KEY_VEHICLE_TYPE
	 * 
	 * JSON type: STRING
	 * 
	 * Description:
	 *     OEM specific information about the vehicle type.
	 *     - defined by OEM,
	 *     - refers to specific carline information (e.g. combination of MY, car assembly form, motorisation, etc.)
	 */
#define VEHICLE_DATA_KEY_VEHICLE_TYPE  2779139997u

	/*
	 * VEHICLE_DATA_KEY_VEHICLE_ID
	 * 
	 * JSON type: STRING
	 * 
	 * Description:
	 *     OEM specific unique identification number.
	 *     - Anonymised identifier that indicates an vehicle uniquely.
	 *     - defined by OEM
	 */
#define VEHICLE_DATA_KEY_VEHICLE_ID  3989704929u

	/*
	 * VEHICLE_DATA_KEY_SEATBELT_BUCKLE_STATUS_RL
	 * 
	 * JSON type: BOOLEAN
	 * 
	 * Description:
	 *     This Signal indicates whether the rear left seatbelt is buckled or not.
	 *     false   seatbelt is not buckled
	 *     true   seatbelt is buckled
	 */
#define VEHICLE_DATA_KEY_SEATBELT_BUCKLE_STATUS_RL  2690051621u

	/*
	 * VEHICLE_DATA_KEY_SEATBELT_BUCKLE_STATUS_RM
	 * 
	 * JSON type: BOOLEAN
	 * 
	 * Description:
	 *     This Signal indicates whether the rear mid seatbelt is buckled or not.
	 *     false   seatbelt is not buckled
	 *     true   seatbelt is buckled
	 */
#define VEHICLE_DATA_KEY_SEATBELT_BUCKLE_STATUS_RM  326972494u

	/*
	 * VEHICLE_DATA_KEY_SEATBELT_BUCKLE_STATUS_RR
	 * 
	 * JSON type: BOOLEAN
	 * 
	 * Description:
	 *     This Signal indicates whether the rear right seatbelt is buckled or not.
	 *     false   seatbelt is not buckled
	 *     true   seatbelt is buckled
	 */
#define VEHICLE_DATA_KEY_SEATBELT_BUCKLE_STATUS_RR  368007571u

	/*
	 * VEHICLE_DATA_KEY_SEATBELT_BUCKLE_STATUS_FL
	 * 
	 * JSON type: BOOLEAN
	 * 
	 * Description:
	 *     This Signal indicates whether the front left seatbelt is buckled or not.
	 *     false   seatbelt is not buckled
	 *     true   seatbelt is buckled
	 */
#define VEHICLE_DATA_KEY_SEATBELT_BUCKLE_STATUS_FL  2893191853u

	/*
	 * VEHICLE_DATA_KEY_SEATBELT_BUCKLE_STATUS_FR
	 * 
	 * JSON type: BOOLEAN
	 * 
	 * Description:
	 *     This Signal indicates whether the front right seatbelt is buckled or not.
	 *     false   seatbelt is not buckled
	 *     true   seatbelt is buckled
	 */
#define VEHICLE_DATA_KEY_SEATBELT_BUCKLE_STATUS_FR  3147888503u

	/*
	 * VEHICLE_DATA_KEY_SEAT_BELT_BUCKELD_STATUS
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 1
	 * 
	 * Description:
	 *     This Signal indicates whether a seatbelt is buckled or not.
	 *     => binary coded
	 *     bit clear (0)   seatbelt is not buckled
	 *     bit set (1)   seatbelt is buckled
	 *     - the following seats are included:
	 *        1: front left
	 *        2: front center
	 *        4:  front right
	 *        8: mid left
	 *        16: mid center
	 *        32: mid right
	 *        64: rear left
	 *       128: rear right
	 *       256: rear center
	 */
#define VEHICLE_DATA_KEY_SEAT_BELT_BUCKELD_STATUS  1049269183u

	/*
	 * VEHICLE_DATA_KEY_SEAT_OCCUPATION_STATUS_FR
	 * 
	 * JSON type: BOOLEAN
	 * 
	 * Description:
	 *     This Signal indicates whether the front right seat is occupated or not.
	 *     false   seat is not occupated
	 *     true   seat is occupated
	 */
#define VEHICLE_DATA_KEY_SEAT_OCCUPATION_STATUS_FR  2196070655u

	/*
	 * VEHICLE_DATA_KEY_SEAT_OCCUPATION_STATUS_FL
	 * 
	 * JSON type: BOOLEAN
	 * 
	 * Description:
	 *     This Signal indicates whether the front left seat is occupated or not.
	 *     false   seat is not occupated
	 *     true   seat is occupated
	 */
#define VEHICLE_DATA_KEY_SEAT_OCCUPATION_STATUS_FL  1357169871u

	/*
	 * VEHICLE_DATA_KEY_SEAT_OCCUPATION_STATUS_RR
	 * 
	 * JSON type: BOOLEAN
	 * 
	 * Description:
	 *     This Signal indicates whether the rear right seat is occupated or not.
	 *     false   seat is not occupated
	 *     true   seat is occupated
	 */
#define VEHICLE_DATA_KEY_SEAT_OCCUPATION_STATUS_RR  1599928823u

	/*
	 * VEHICLE_DATA_KEY_SEAT_OCCUPATION_STATUS_RM
	 * 
	 * JSON type: BOOLEAN
	 * 
	 * Description:
	 *     This Signal indicates whether the rear mid seat is occupated or not.
	 *     false   seat is not occupated
	 *     true   seat is occupated
	 */
#define VEHICLE_DATA_KEY_SEAT_OCCUPATION_STATUS_RM  1410201613u

	/*
	 * VEHICLE_DATA_KEY_SEAT_OCCUPATION_STATUS_RL
	 * 
	 * JSON type: BOOLEAN
	 * 
	 * Description:
	 *     This Signal indicates whether the rear left seat is occupated or not.
	 *     false   seat is not occupated
	 *     true   seat is occupated
	 */
#define VEHICLE_DATA_KEY_SEAT_OCCUPATION_STATUS_RL  3896901882u

	/*
	 * VEHICLE_DATA_KEY_SEAT_OCCUPATION_STATUS
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 1
	 * 
	 * Description:
	 *     This Signal indicates whether a seat is occupated or not.
	 *     => binary coded
	 *     bit clear (0)   seat is not occupated
	 *     bit set (1)  seat is occupated
	 *     - the following seats are included:
	 *        1: front left
	 *        2: front center
	 *        4:  front right
	 *        8: mid left
	 *        16: mid center
	 *        32: mid right
	 *        64: rear left
	 *        128: rear right
	 *       256: rear center
	 */
#define VEHICLE_DATA_KEY_SEAT_OCCUPATION_STATUS  138638589u

	/*
	 * VEHICLE_DATA_KEY_IS_NIGHT
	 * 
	 * JSON type: BOOLEAN
	 * 
	 * Description:
	 *     This signal indicates UI settings are in DAY or NIGHT mode.
	 *     true    vehicle is in NIGHT mode
	 *     false   vehicle is in DAY mode
	 */
#define VEHICLE_DATA_KEY_IS_NIGHT  3u

	/*
	 * VEHICLE_DATA_KEY_GEOLOCATION_NMEA
	 * 
	 * JSON type: STRING
	 * 
	 * Description:
	 *     This signal informs about the current vehicle position.  The coding of the geo location corresponds to the NMEA 0183 specification.
	 *     value   GGA or RMC NMEA strings
	 */
#define VEHICLE_DATA_KEY_GEOLOCATION_NMEA  1u

	/*
	 * VEHICLE_DATA_KEY_IS_MOVING
	 * 
	 * JSON type: BOOLEAN
	 * 
	 * Description:
	 *     This signal indicates whether the vehicle is moving or not. The threshold for this event is OEM specific, but typically between 3 und 5 km/h.
	 *     true   vehicle is moving
	 *     false   vehicle is not moving
	 */
#define VEHICLE_DATA_KEY_IS_MOVING  2u

	/*
	 * VEHICLE_DATA_KEY_DTC_IVI
	 * 
	 * JSON type: STRING
	 * 
	 * Description:
	 *     Provides Diagnostic Trouble Codes from IVI
	 *     The string contains the five-digit OBD2 code.
	 *     First digit: letter encoding the origin (B=Body, C=Chassis, P=Powertrain, U=Network)
	 *     Second digit = 0 SAE defined, =1 OEM defined
	 *     Third digit = Subsystem
	 *     Digit 4 and 5: fault code
	 *     JSON string example:
	 *     { "value": "P0100" }
	 *     This is SAE code "Mass or Volume Air Flow 'A' Circuit"
	 */
#define VEHICLE_DATA_KEY_DTC_IVI  1473474142u

	/*
	 * VEHICLE_DATA_KEY_DTC_ALL
	 * 
	 * JSON type: STRING
	 * 
	 * Description:
	 *     Provides Diagnostic Trouble Codes from entire vehicle (including IVI)
	 *     The string contains the five-digit OBD2 code.
	 *     First digit: letter encoding the origin (B=Body, C=Chassis, P=Powertrain, U=Network)
	 *     Second digit = 0 SAE defined, =1 OEM defined
	 *     Third digit = Subsystem
	 *     Digit 4 and 5: fault code
	 *     JSON string example:
	 *     { "value": "P0100" }
	 *     This is SAE code "Mass or Volume Air Flow 'A' Circuit"
	 */
#define VEHICLE_DATA_KEY_DTC_ALL  4162619749u

	/*
	 * VEHICLE_DATA_KEY_LAMPS_STATUS
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 72057594037927900
	 * 
	 * Description:
	 *     The signal indicates the status of one or more vehicle lamps.
	 *     => binary coded, 2bit for each lamp indicating
	 *        00 - off and okay
	 *        01 - on and okay
	 *        10 - defect
	 *        11 - reserved
	 *     Included vehicle lamps - add value to indicate status (mask for lamp):
	 *     Parking light front left (0x03 / 3)
	 *      0x1 - 1 - on
	 *      0x2 - 2 - defect
	 *     Parking light front right (0x0C / 12)
	 *      0x4 - 4 - on
	 *      0x8 - 8 - defect
	 *     Parking light rear left (0x030 / 48)
	 *      0x10 - 16 - on
	 *      0x20 - 32 - defect
	 *     Parking ligth rear right (0x0C0 / 192)
	 *      0x40 - 64 - on
	 *      0x80 - 128 - defect
	 *     low beam left (0x0300 / 768)
	 *      0x100 - 256 - on
	 *      0x200 - 512 - defect
	 *     low beam right (0x0C00 / 3072)
	 *      0x400 - 1024 - on
	 *      0x800 - 2048 - defect
	 *     full beam left (0x03000 / 12288)
	 *      0x1000 - 4096 - on
	 *      0x2000 - 8192 - defect
	 *     full beam right (0x0C000 / 49152)
	 *      0x4000 - 16384 - on
	 *      0x8000 - 32768 - defect
	 *     indicator front left (0x030000 / 196608)
	 *      0x10000 - 65536 - on
	 *      0x20000 - 131072 - defect
	 *     indicator front right (0x0C0000 / 786432)
	 *      0x40000 - 262144 - on
	 *      0x80000 - 524288 - defect
	 *     indicator rear left (0x0300000 / 3145728)
	 *      0x100000 - 1048576 - on
	 *      0x200000 - 2097152 - defect
	 *     indicator rear right (0x0C00000 / 12582912)
	 *      0x400000 - 4194304 - on
	 *      0x800000 - 8388608 - defect
	 *     fog lamp left (0x03000000 / 50331648)
	 *      0x1000000 - 16777216 - on
	 *      0x2000000 - 33554432 - defect
	 *     fog lamp right (0x0C000000 / 201326592)
	 *      0x4000000 - 67108864 - on
	 *      0x8000000 - 134217728 - defect
	 *     daylight left (0x030000000 / 805306368)
	 *      0x10000000 - 268435456 - on
	 *      0x20000000 - 536870912 - defect
	 *     daylight right (0x0C0000000 / 3221225472)
	 *      0x40000000 - 1073741824 - on
	 *      0x80000000 - 2147483648 - defect
	 *     bending light left (0x0300000000 / 12884901888)
	 *      0x100000000 - 4294967296 - on
	 *      0x200000000 - 8589934592 - defect
	 *     bending light right (0x0C00000000 / 51539607552)
	 *      0x400000000 - 17179869184 - on
	 *      0x800000000 - 34359738368 - defect
	 *     tail lamp left  (0x03000000000 / 206158430208)
	 *      0x1000000000 - 68719476736 - on
	 *      0x2000000000 - 137438953472 - defect
	 *     tail lamp right (0x0C000000000 / 824633720832)
	 *      0x4000000000 - 274877906944 - on
	 *      0x8000000000 - 549755813888 - defect
	 *     brake light left (0x030000000000 / 3298534883328)
	 *      0x10000000000 - 1099511627776 - on
	 *      0x20000000000 - 2199023255552 - defect
	 *     brake light right (0x0C0000000000 / 13194139533312)
	 *      0x40000000000 - 4398046511104 - on
	 *      0x80000000000 - 8796093022208 - defect
	 *     brake light center (0x0300000000000 / 52776558133248)
	 *      0x100000000000 - 17592186044416 - on
	 *      0x200000000000 - 35184372088832 - defect
	 *     rear fog lamp left (0x0C00000000000 / 211106232532992)
	 *      0x400000000000 - 70368744177664 - on
	 *      0x800000000000 - 140737488355328 - defect
	 *     rear fog lamp right (0x03000000000000 / 844424930131968)
	 *      0x1000000000000 - 281474976710656 - on
	 *      0x2000000000000 - 562949953421312 - defect
	 *     reversing light left (0x0C000000000000 / 3377699720527872)
	 *      0x4000000000000 - 1125899906842624 - on
	 *      0x8000000000000 - 2251799813685248 - defect
	 *     reversing light right (0x030000000000000 / 13510798882111488)
	 *      0x10000000000000 - 4503599627370496 - on
	 *      0x20000000000000 - 9007199254740992 - defect
	 *     tag light (0x0C0000000000000 / 54043195528445952)
	 *      0x40000000000000 - 18014398509481984 - on
	 *      0x80000000000000 - 36028797018963968 - defect
	 */
#define VEHICLE_DATA_KEY_LAMPS_STATUS  40346299u

	/*
	 * VEHICLE_DATA_KEY_PARKING_SENSORS
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: -1
	 *      maximum value: 1000
	 *      unit         : cm
	 * 
	 * Description:
	 *     The signal informs about the status of the parking sensors (obstacle visual distance). 
	 *     => composite numerical value
	 *     - negative values: sensor is defect
	 *     - 0: sensor is off
	 *     - The definitions allow up to six sensors for front and rear direction. These are labeled (from left to right):
	 *       LL - LM - LR - RL - RM - RR
	 *     Use LL and RR for two-sensor systems; LL/LM/RM/RR for four-sensor systems.   
	 *     JSON example:
	 *     { "value": { "front": { "LL": 30, "LM": 40, "LR": 60}, "rear": {"RM": -1}}}
	 *     This describes a six sensor system with an obstacle near front left corner of the vehicle and one of the rear sensors defective
	 *     It is not necessary to include sensors not active, not mounted or obstacle out of detection range; "off" will be assumed in these cases.
	 */
#define VEHICLE_DATA_KEY_PARKING_SENSORS  2014417060u

	/*
	 * VEHICLE_DATA_KEY_RADIO_STATON
	 * 
	 * JSON type: STRING
	 * 
	 * Description:
	 *     The signal informs about the selected radio station. TA (Traffic Announcements) are included.
	 *     => composite numerical/string value
	 *      - Included station information:
	 *        frequency in KHz
	 *        station name
	 *        PiCode (radio station program identification)
	 *     JSON example:
	 *     { "value": { "frequency": 92100, "picode": "D382" }}
	 *     Note for station name: Some broadcasters use the station name (RDS PS code) dynamically for example to display interpret and title name of current track. Whereever possible, this information shall not be transferred. Instead use the name of the broadcaster and program if known (e.g. NDR2).
	 */
#define VEHICLE_DATA_KEY_RADIO_STATON  2322590304u

	/*
	 * VEHICLE_DATA_KEY_VEHICLE_MILAGE
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 9999999
	 *      unit         : m
	 * 
	 * Description:
	 *     The signal provides the vehicle mileage in m.
	 *     => numercial
	 */
#define VEHICLE_DATA_KEY_VEHICLE_MILAGE  656363884u

	/*
	 * VEHICLE_DATA_KEY_DAYS_TO_NEXT_MAINTENANCE
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: -10950
	 *      maximum value: 10950
	 * 
	 * Description:
	 *     The signal provides the number of days before next maintenance. If value is negative, maintance is exceeded.
	 */
#define VEHICLE_DATA_KEY_DAYS_TO_NEXT_MAINTENANCE  1875526729u

	/*
	 * VEHICLE_DATA_KEY_DISTANCE_NEXT_MAINTANCE
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: -9999999
	 *      maximum value: 9999999
	 *      unit         : m
	 * 
	 * Description:
	 *     The signal indicates the distance until the next maintenance. If distance is negative, maintanance is exceeded.
	 */
#define VEHICLE_DATA_KEY_DISTANCE_NEXT_MAINTANCE  1933797964u

	/*
	 * VEHICLE_DATA_KEY_ENIGINE_OIL_LEVEL
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 150
	 * 
	 * Description:
	 *     The signal indicates the oil level of the engine in percentage.
	 *     Note: Value might exceed 100% if the system is able to detect overfilling.
	 */
#define VEHICLE_DATA_KEY_ENIGINE_OIL_LEVEL  2859131701u

	/*
	 * VEHICLE_DATA_KEY_DISTANCE_LEFT_TO_DESTINATION
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 25800000
	 *      unit         : m
	 * 
	 * Description:
	 *     The signal provides the calculated distance left to the destination from the onboard navigation system.
	 */
#define VEHICLE_DATA_KEY_DISTANCE_LEFT_TO_DESTINATION  2905673758u

	/*
	 * VEHICLE_DATA_KEY_PARKING_SLOT_DETECTION_SENSOR
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: -1
	 *      maximum value: 1000
	 *      unit         : cm
	 * 
	 * Description:
	 *     The signal provides information from the parking slot detection sensors. 
	 *     => composite numerical
	 *     <0 - defect
	 *     0 - sensor off
	 *     >0 - distance to obstacle
	 *     - Two sensors for each side of the vehicle are defined:
	 *        left front
	 *        left rear
	 *        right front
	 *        right rear
	 *     JSON example:
	 *     { "value": { "right front": 300, "right rear": 40 } }
	 *     This describes the case "vehicle nose already beside parking spot, vehicle tail still beside next car parking".
	 *     { "value": { "right front": 300, "right rear": 270 } }
	 *     This describes the case "vehicle beside parking spot (large enough)".
	 */
#define VEHICLE_DATA_KEY_PARKING_SLOT_DETECTION_SENSOR  182794228u

	/*
	 * VEHICLE_DATA_KEY_VERTICAL_ACCELERATION
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: -12
	 *      maximum value: 12
	 *      unit         : m/s^2
	 * 
	 * Description:
	 *     Value of acceleration in z-axis, positive values upwards, negativ values downwards.
	 *     -12 .. 12 m/s^2; increments of 0.1 possible
	 */
#define VEHICLE_DATA_KEY_VERTICAL_ACCELERATION  2863233776u

	/*
	 * VEHICLE_DATA_KEY_LONGITUDINAL_ACCELERATION
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: -12
	 *      maximum value: 12
	 *      unit         : m/s^2
	 * 
	 * Description:
	 *     Value for acceleration in x-axis. 
	 *     When the vehicle accelerates up-hill (noseup), the reading would be positive, when it accelerats downhill (nosedown) then reading would be negative. On flat surface the reading would be '0' (zero).
	 *     -12 .. 12 m/s^2; increments of 0.1 possible
	 */
#define VEHICLE_DATA_KEY_LONGITUDINAL_ACCELERATION  291948929u

	/*
	 * VEHICLE_DATA_KEY_AIRBAG_TRIGGER_STATUS
	 * 
	 * JSON type: BOOLEAN
	 * 
	 * Description:
	 *     The signal indicates if an airbag of the vehicle is activated.
	 */
#define VEHICLE_DATA_KEY_AIRBAG_TRIGGER_STATUS  1952473801u

	/*
	 * VEHICLE_DATA_KEY_CURRENT_FUEL_CONSUMPTION
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 10000
	 *      unit         : ml/s
	 * 
	 * Description:
	 *     The signal provides the current fuel consumption of the vehicle in milliliters per second.
	 */
#define VEHICLE_DATA_KEY_CURRENT_FUEL_CONSUMPTION  3310178937u

	/*
	 * VEHICLE_DATA_KEY_TYRE_STATUS
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 255
	 * 
	 * Description:
	 *     The signal indicated warnings regarding vehicle tyres. 
	 *     Status: high temperature warning, preasure warning, okay
	 *     => binary coded, 2bit for each tyre status
	 *        00 - no warning, okay
	 *        01 - high temperature warning
	 *        10 - preasure warning
	 *        11 -  high temperature and preasure warning
	 *     - The following tyres are included  - add value to indicate status (mask for tyre)
	 *     Tyre  front left (0x03 / 3)
	 *      0x1 - 1 - high temperature warning
	 *      0x2 - 2 - preasure warning
	 *     Tyre  front right (0x0C / 12)
	 *      0x4 - 4 - high temperature warning
	 *      0x8 - 8 - preasure warning
	 *     Tyre  rear left (0x030 / 48)
	 *      0x10 - 16 - high temperature warning
	 *      0x20 - 32 - defect
	 *     Tyre  rear right (0x0C0 / 192)
	 *      0x40 - 64 - high temperature warning
	 *      0x80 - 128 - preasure warning
	 */
#define VEHICLE_DATA_KEY_TYRE_STATUS  667948030u

	/*
	 * VEHICLE_DATA_KEY_ROLE_ANGLE
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: -180
	 *      maximum value: 180
	 *      unit         : deg
	 * 
	 * Description:
	 *     The signal indicates the inclination angle of a two wheeler. 
	 *     Unit degress from vertical, positive to the right, negative to the left
	 */
#define VEHICLE_DATA_KEY_ROLE_ANGLE  1120875974u

	/*
	 * VEHICLE_DATA_KEY_FUEL_VOLUME
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 300
	 *      unit         : l or kwh
	 * 
	 * Description:
	 *     Fuel tank volume(s) in liter or battery capacity in kilo watts per hour. 
	 *     => composite numerical
	 *     Values given for main and optional a secondary tank.
	 *     JSON example:
	 *     { "value": { "main": 85 } } // normal use case
	 *     { "value": { "main": 85, "secondary": 30 } } // additional LPG
	 */
#define VEHICLE_DATA_KEY_FUEL_VOLUME  22463667u

	/*
	 * VEHICLE_DATA_KEY_FUEL_LEVEL
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 100
	 * 
	 * Description:
	 *     Fuel level or batter charging status in percent.
	 *     => composite numerical
	 *     fuel level order for the tnaks shall match the one used in _FUEL_VOLUME
	 */
#define VEHICLE_DATA_KEY_FUEL_LEVEL  3812856091u

	/*
	 * VEHICLE_DATA_KEY_FUEL_TYPE
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 100
	 * 
	 * Description:
	 *     The signal indicates the type of fuel of the vehicle.
	 *     _FUEL_TYPE
	 *     => composite numerical
	 *     tank order shall match the one used in _FUEL_VOLUME
	 *     0 - gasoline
	 *     1 - unleaded gasoline
	 *     2 - unleaded gasoline E10
	 *     3 - unleaded gasoline E85
	 *     10 - Diesel
	 *     11 - Biodiesel
	 *     20 - LPG (liquefied petroleum gas)
	 *     21 - CNG (compressed natural gas)
	 *     100 - electric current
	 */
#define VEHICLE_DATA_KEY_FUEL_TYPE  3406323193u

	/*
	 * VEHICLE_DATA_KEY_HEADING
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 360
	 *      unit         : deg
	 * 
	 * Description:
	 *     The signal inidcates the heading of a vehicle relativly to north. 
	 *     _HEADING
	 *     0= nord, 90= east, etc. 
	 */
#define VEHICLE_DATA_KEY_HEADING  4052423355u

	/*
	 * VEHICLE_DATA_KEY_PITCH_ANGLE
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: -180
	 *      maximum value: 180
	 *      unit         : deg
	 * 
	 * Description:
	 *     The signal indicates the pitch angle of a vehicle. 
	 *     Unit degress from horizontal. Nose down is negative and nose up is positive
	 */
#define VEHICLE_DATA_KEY_PITCH_ANGLE  3732206196u

	/*
	 * VEHICLE_DATA_KEY_ENGINE_SPEED_ACCURATE
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 8191
	 *      unit         : RPM
	 * 
	 * Description:
	 *     The signal indigates the engine speed in rpm.
	 */
#define VEHICLE_DATA_KEY_ENGINE_SPEED_ACCURATE  3696623178u

	/*
	 * VEHICLE_DATA_KEY_LOW_BATTERY_CHARGE_WARNING
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 3
	 * 
	 * Description:
	 *     The signal indicates battery low state of charge warning on a (H)EV.
	 */
#define VEHICLE_DATA_KEY_LOW_BATTERY_CHARGE_WARNING  3236143375u

	/*
	 * VEHICLE_DATA_KEY_VEHICLE_SPEED_ACCURATE
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: -100
	 *      maximum value: 400
	 *      unit         : km/h
	 * 
	 * Description:
	 *     The signal indigates the vehicle speed in km/h.
	 *     The value may become negative if the vehicle drives with reverse gear. Resolution of 1km/h is sufficient.
	 */
#define VEHICLE_DATA_KEY_VEHICLE_SPEED_ACCURATE  2099443710u

	/*
	 * VEHICLE_DATA_KEY_BATTERY_VOLTAGE
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 30
	 *      unit         : V
	 * 
	 * Description:
	 *     Current measured voltage of the vehicle (low-voltage) battery.
	 *     0-30        battery voltage in V
	 */
#define VEHICLE_DATA_KEY_BATTERY_VOLTAGE  750836716u

	/*
	 * VEHICLE_DATA_KEY_BATTERY_CHARGING_STATUS
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 100
	 *      unit         : %
	 * 
	 * Description:
	 *     Battery charging status
	 *     0-100      battery charging status in %
	 */
#define VEHICLE_DATA_KEY_BATTERY_CHARGING_STATUS  1127779612u

	/*
	 * VEHICLE_DATA_KEY_TYRE_TPMS
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 3
	 * 
	 * Description:
	 *     The purpose of the tyre pressure monitoring system (TPMS) is to warn that at least one or more tyres are significantly under-inflated, possibly creating unsafe driving conditions. 
	 *     0      TPMS OK
	 *     1      TPMS failure
	 *     2      Invalid
	 *     >2    reserved by OEM
	 */
#define VEHICLE_DATA_KEY_TYRE_TPMS  2919223520u

	/*
	 * VEHICLE_DATA_KEY_TYRE_STATUS_EXT
	 * 
	 * JSON type: NUMERICAL
	 * 
	 * Description:
	 *     The signal provides extended information regarding temperature and pressure of the individual tyres.
	 *     The data format based on the "Composite Value" vehicle data type definition where the numerical temperature value and a numerical value for the pressure level is given per tyre.
	 *     {"value": {
	 *        "StatusExt_FL":  {                  // tyre status extended - front left
	 *           "Temp": <temperature>       // refer [tyre temperature] 
	 *           "PW": <pressure warning>  // refer [tyre pressure warning] 
	 *        }, 
	 *        "StatusExt_FR":  {                  // tyre status extended - front right
	 *           "Temp": <temperature>       // refer [tyre temperature] 
	 *           "PW": <pressure warning>  // refer [tyre pressure warning] 
	 *        }, 
	 *        "StatusExt_RL":  {                  // tyre status extended - rear left
	 *           "Temp": <temperature>       // refer [tyre temperature]
	 *           "PW": <pressure warning>  // refer [tyre pressure warning]
	 *        }, 
	 *        "StatusExt_RR":  {                  // tyre status extended - rear right
	 *           "Temp": <temperature>       // refer [tyre temperature] 
	 *           "PW": <pressure warning>  // refer [tyre pressure warning]
	 *        }
	 *     }  } 
	 *     [tyre temperature]
	 *        factor: 1
	 *        min value: 0 
	 *        min value: -50
	 *        max value: 200 // relates to -50...200 degC
	 *     [pressure warning]
	 *        0   no warning, okay
	 *        1   over inflation warning
	 *        2   under inflation warning
	 *        3   sensor failure
	 */
#define VEHICLE_DATA_KEY_TYRE_STATUS_EXT  2439270252u

	/*
	 * VEHICLE_DATA_KEY_AVERAGE_FUEL_CONSUMPTION
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 100
	 *      unit         : l/100km
	 * 
	 * Description:
	 *     This signal represents the average fuel consumption in l/100km.
	 *     0-100    liter per 100 km
	 */
#define VEHICLE_DATA_KEY_AVERAGE_FUEL_CONSUMPTION  2365322197u

	/*
	 * VEHICLE_DATA_KEY_AVERAGE_SPEED
	 * 
	 * JSON type: NUMERICAL
	 *      minimum value: 0
	 *      maximum value: 500
	 *      unit         : km/h
	 * 
	 * Description:
	 *     Average vehicle speed
	 *     0-500   speed
	 */
#define VEHICLE_DATA_KEY_AVERAGE_SPEED  1159075832u


#ifdef __cplusplus
}
#endif

#endif /* MYSPIN_VEHICLE_DATA_KEYS_BSOT_H_ */

