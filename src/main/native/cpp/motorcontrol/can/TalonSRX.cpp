#include "ctre/phoenix/motorcontrol/can/TalonSRX.h"
#include "ctre/phoenix/motorcontrol/SensorCollection.h"
#include "ctre/phoenix/cci/MotController_CCI.h"

using namespace ctre::phoenix;
using namespace ctre::phoenix::motorcontrol::can;
using namespace ctre::phoenix::motorcontrol;

//Construct defaults for utils
TalonSRXPIDSetConfiguration  TalonSRXPIDSetConfigUtil::_default;
TalonSRXConfiguration TalonConfigUtil::_default;

/**
 * Constructor
 * @param deviceNumber [0,62]
 */
TalonSRX::TalonSRX(int deviceNumber) :
    BaseMotorController(deviceNumber | 0x02040000) {
    _sensorColl = new motorcontrol::SensorCollection((void*) m_handle);
}
/**
 *
 * Destructor
 */
TalonSRX::~TalonSRX() {
	delete _sensorColl;
	_sensorColl = 0;
}
/**
 * Select the feedback device for the motor controller.
 *
 * @param feedbackDevice
 *            Feedback Device to select.
 * @param pidIdx
 *            0 for Primary closed-loop. 1 for auxiliary closed-loop.
 * @param timeoutMs
 *            Timeout value in ms. If nonzero, function will wait for
 *            config success and report an error if it times out.
 *            If zero, no blocking or checking is performed.
 * @return Error Code generated by function. 0 indicates no error.
 */
ctre::phoenix::ErrorCode TalonSRX::ConfigSelectedFeedbackSensor(FeedbackDevice feedbackDevice,
		int pidIdx, int timeoutMs) {
	return BaseMotorController::ConfigSelectedFeedbackSensor(feedbackDevice,
			pidIdx, timeoutMs);
}
/**
 * Select the remote feedback device for the motor controller.
 * Most CTRE CAN motor controllers will support remote sensors over CAN.
 *
 * @param feedbackDevice
 *            Remote Feedback Device to select.
 * @param pidIdx
 *            0 for Primary closed-loop. 1 for auxiliary closed-loop.
 * @param timeoutMs
 *            Timeout value in ms. If nonzero, function will wait for
 *            config success and report an error if it times out.
 *            If zero, no blocking or checking is performed.
 * @return Error Code generated by function. 0 indicates no error.
 */
ctre::phoenix::ErrorCode TalonSRX::ConfigSelectedFeedbackSensor(RemoteFeedbackDevice feedbackDevice,
		int pidIdx, int timeoutMs) {
	return BaseMotorController::ConfigSelectedFeedbackSensor(feedbackDevice,
			pidIdx, timeoutMs);
}
/**
 * Sets the period of the given status frame.
 *
 * User ensure CAN Bus utilization is not high.
 *
 * This setting is not persistent and is lost when device is reset.
 * If this is a concern, calling application can use HasResetOccurred()
 * to determine if the status frame needs to be reconfigured.
 *
 * @param frame
 *            Frame whose period is to be changed.
 * @param periodMs
 *            Period in ms for the given frame.
 * @param timeoutMs
 *            Timeout value in ms. If nonzero, function will wait for
 *            config success and report an error if it times out.
 *            If zero, no blocking or checking is performed.
 * @return Error Code generated by function. 0 indicates no error.
 */
ctre::phoenix::ErrorCode TalonSRX::SetStatusFramePeriod(StatusFrameEnhanced frame,
		uint8_t periodMs, int timeoutMs) {
	return BaseMotorController::SetStatusFramePeriod(frame, periodMs, timeoutMs);
}
/**
 * Sets the period of the given status frame.
 *
 * User ensure CAN Bus utilization is not high.
 *
 * This setting is not persistent and is lost when device is reset.
 * If this is a concern, calling application can use HasResetOccurred()
 * to determine if the status frame needs to be reconfigured.
 *
 * @param frame
 *            Frame whose period is to be changed.
 * @param periodMs
 *            Period in ms for the given frame.
 * @param timeoutMs
 *            Timeout value in ms. If nonzero, function will wait for
 *            config success and report an error if it times out.
 *            If zero, no blocking or checking is performed.
 * @return Error Code generated by function. 0 indicates no error.
 */
ctre::phoenix::ErrorCode TalonSRX::SetStatusFramePeriod(StatusFrame frame,
		uint8_t periodMs, int timeoutMs) {
	return BaseMotorController::SetStatusFramePeriod(frame, periodMs, timeoutMs);
}
/**
 * Gets the period of the given status frame.
 *
 * @param frame
 *            Frame to get the period of.
 * @param timeoutMs
 *            Timeout value in ms. If nonzero, function will wait for
 *            config success and report an error if it times out.
 *            If zero, no blocking or checking is performed.
 * @return Period of the given status frame.
 */
int TalonSRX::GetStatusFramePeriod(StatusFrameEnhanced frame, int timeoutMs) {
	return BaseMotorController::GetStatusFramePeriod(frame, timeoutMs);
}
/**
 * Gets the period of the given status frame.
 *
 * @param frame
 *            Frame to get the period of.
 * @param timeoutMs
 *            Timeout value in ms. If nonzero, function will wait for
 *            config success and report an error if it times out.
 *            If zero, no blocking or checking is performed.
 * @return Period of the given status frame.
 */
int TalonSRX::GetStatusFramePeriod(StatusFrame frame, int timeoutMs) {
	return BaseMotorController::GetStatusFramePeriod(frame, timeoutMs);
}
/**
 * Gets the output current of the motor controller.
 *
 * @return The output current (in amps).
 */
double TalonSRX::GetOutputCurrent() {
	return BaseMotorController::GetOutputCurrent();
}
/**
 * Configures the period of each velocity sample.
 * Every 1ms a position value is sampled, and the delta between that sample
 * and the position sampled kPeriod ms ago is inserted into a filter.
 * kPeriod is configured with this function.
 *
 * @param period
 *            Desired period for the velocity measurement. @see
 *            #VelocityMeasPeriod
 * @param timeoutMs
 *            Timeout value in ms. If nonzero, function will wait for
 *            config success and report an error if it times out.
 *            If zero, no blocking or checking is performed.
 * @return Error Code generated by function. 0 indicates no error.
 */
ctre::phoenix::ErrorCode TalonSRX::ConfigVelocityMeasurementPeriod(VelocityMeasPeriod period,
		int timeoutMs) {
	return BaseMotorController::ConfigVelocityMeasurementPeriod(period,
			timeoutMs);
}
/**
 * Sets the number of velocity samples used in the rolling average velocity
 * measurement.
 *
 * @param windowSize
 *            Number of samples in the rolling average of velocity
 *            measurement. Valid values are 1,2,4,8,16,32. If another
 *            value is specified, it will truncate to nearest support value.
 * @param timeoutMs
 *            Timeout value in ms. If nonzero, function will wait for
 *            config success and report an error if it times out.
 *            If zero, no blocking or checking is performed.
 * @return Error Code generated by function. 0 indicates no error.
 */
ctre::phoenix::ErrorCode TalonSRX::ConfigVelocityMeasurementWindow(int windowSize,
		int timeoutMs) {
	return BaseMotorController::ConfigVelocityMeasurementWindow(windowSize,
			timeoutMs);
}
/**
 * Configures a limit switch for a local/remote source.
 *
 * For example, a CAN motor controller may need to monitor the Limit-R pin
 * of another Talon, CANifier, or local Gadgeteer feedback connector.
 *
 * If the sensor is remote, a device ID of zero is assumed.
 * If that's not desired, use the four parameter version of this function.
 *
 * @param limitSwitchSource
 *            Limit switch source. @see #LimitSwitchSource
 *            User can choose between the feedback connector, remote Talon SRX, CANifier, or deactivate the feature.
 * @param normalOpenOrClose
 *            Setting for normally open, normally closed, or disabled. This setting
 *            matches the Phoenix Tuner drop down.
 * @param timeoutMs
 *            Timeout value in ms. If nonzero, function will wait for
 *            config success and report an error if it times out.
 *            If zero, no blocking or checking is performed.
 * @return Error Code generated by function. 0 indicates no error.
 */
ctre::phoenix::ErrorCode TalonSRX::ConfigForwardLimitSwitchSource(
		LimitSwitchSource limitSwitchSource,
		LimitSwitchNormal normalOpenOrClose, int timeoutMs) {

	return BaseMotorController::ConfigForwardLimitSwitchSource(
			limitSwitchSource, normalOpenOrClose, timeoutMs);
}
/**
 * Configures a limit switch for a local/remote source.
 *
 * For example, a CAN motor controller may need to monitor the Limit-R pin
 * of another Talon, CANifier, or local Gadgeteer feedback connector.
 *
 * If the sensor is remote, a device ID of zero is assumed.
 * If that's not desired, use the four parameter version of this function.
 *
 * @param limitSwitchSource
 *            Limit switch source. @see #LimitSwitchSource
 *            User can choose between the feedback connector, remote Talon SRX, CANifier, or deactivate the feature.
 * @param normalOpenOrClose
 *            Setting for normally open, normally closed, or disabled. This setting
 *            matches the Phoenix Tuner drop down.
 * @param timeoutMs
 *            Timeout value in ms. If nonzero, function will wait for
 *            config success and report an error if it times out.
 *            If zero, no blocking or checking is performed.
 * @return Error Code generated by function. 0 indicates no error.
 */
ctre::phoenix::ErrorCode TalonSRX::ConfigReverseLimitSwitchSource(
		LimitSwitchSource limitSwitchSource,
		LimitSwitchNormal normalOpenOrClose, int timeoutMs) {
	return BaseMotorController::ConfigReverseLimitSwitchSource(
			limitSwitchSource, normalOpenOrClose, timeoutMs);
}
/**
 * Configures the forward limit switch for a remote source.
 * For example, a CAN motor controller may need to monitor the Limit-F pin
 * of another Talon or CANifier.
 *
 * @param limitSwitchSource
 *            Remote limit switch source. @see #RemoteLimitSwitchSource
 *            User can choose between a remote Talon SRX, CANifier, or deactivate the feature.
 * @param normalOpenOrClose
 *            Setting for normally open, normally closed, or disabled. This setting
 *            matches the Phoenix Tuner drop down.
 * @param deviceID
 *            Device ID of remote source (Talon SRX or CANifier device ID).
 * @param timeoutMs
 *            Timeout value in ms. If nonzero, function will wait for
 *            config success and report an error if it times out.
 *            If zero, no blocking or checking is performed.
 * @return Error Code generated by function. 0 indicates no error.
 */
ctre::phoenix::ErrorCode TalonSRX::ConfigForwardLimitSwitchSource(
		RemoteLimitSwitchSource limitSwitchSource,
		LimitSwitchNormal normalOpenOrClose, int deviceID, int timeoutMs) {

	return BaseMotorController::ConfigForwardLimitSwitchSource(
			limitSwitchSource, normalOpenOrClose, deviceID, timeoutMs);
}
/**
 * Configures the reverse limit switch for a remote source.
 * For example, a CAN motor controller may need to monitor the Limit-R pin
 * of another Talon or CANifier.
 *
 * @param limitSwitchSource
 *            Remote limit switch source. @see #RemoteLimitSwitchSource
 *            User can choose between a remote Talon SRX, CANifier, or deactivate the feature.
 * @param normalOpenOrClose
 *            Setting for normally open, normally closed, or disabled. This setting
 *            matches the Phoenix Tuner drop down.
 * @param deviceID
 *            Device ID of remote source (Talon SRX or CANifier device ID).
 * @param timeoutMs
 *            Timeout value in ms. If nonzero, function will wait for
 *            config success and report an error if it times out.
 *            If zero, no blocking or checking is performed.
 * @return Error Code generated by function. 0 indicates no error.
 */
ctre::phoenix::ErrorCode TalonSRX::ConfigReverseLimitSwitchSource(
		RemoteLimitSwitchSource limitSwitchSource,
		LimitSwitchNormal normalOpenOrClose, int deviceID, int timeoutMs) {

	return BaseMotorController::ConfigReverseLimitSwitchSource(
			limitSwitchSource, normalOpenOrClose, deviceID, timeoutMs);
}

//------ Current Lim ----------//
/**
 * Configure the peak allowable current (when current limit is enabled).
 *
 * Current limit is activated when current exceeds the peak limit for longer than the peak duration.
 * Then software will limit to the continuous limit.
 * This ensures current limiting while allowing for momentary excess current events.
 *
 * For simpler current-limiting (single threshold) use ConfigContinuousCurrentLimit()
 * and set the peak to zero: ConfigPeakCurrentLimit(0).
 *
 * @param amps	Amperes to limit.
 * @param timeoutMs
 *            Timeout value in ms. If nonzero, function will wait for
 *            config success and report an error if it times out.
 *            If zero, no blocking or checking is performed.
 */
ctre::phoenix::ErrorCode TalonSRX::ConfigPeakCurrentLimit(int amps, int timeoutMs) {
	return c_MotController_ConfigPeakCurrentLimit(m_handle, amps, timeoutMs);
}
/**
 * Configure the peak allowable duration (when current limit is enabled).
 *
 * Current limit is activated when current exceeds the peak limit for longer than the peak duration.
 * Then software will limit to the continuous limit.
 * This ensures current limiting while allowing for momentary excess current events.
 *
 * For simpler current-limiting (single threshold) use ConfigContinuousCurrentLimit()
 * and set the peak to zero: ConfigPeakCurrentLimit(0).
 *
 * @param milliseconds How long to allow current-draw past peak limit.
 * @param timeoutMs
 *            Timeout value in ms. If nonzero, function will wait for
 *            config success and report an error if it times out.
 *            If zero, no blocking or checking is performed.
 */
ctre::phoenix::ErrorCode TalonSRX::ConfigPeakCurrentDuration(int milliseconds, int timeoutMs) {
	return c_MotController_ConfigPeakCurrentDuration(m_handle, milliseconds,
			timeoutMs);
}
/**
 * Configure the continuous allowable current-draw (when current limit is enabled).
 *
 * Current limit is activated when current exceeds the peak limit for longer than the peak duration.
 * Then software will limit to the continuous limit.
 * This ensures current limiting while allowing for momentary excess current events.
 *
 * For simpler current-limiting (single threshold) use ConfigContinuousCurrentLimit()
 * and set the peak to zero: ConfigPeakCurrentLimit(0).
 *
 * @param amps	Amperes to limit.
 * @param timeoutMs
 *            Timeout value in ms. If nonzero, function will wait for
 *            config success and report an error if it times out.
 *            If zero, no blocking or checking is performed.
 */
ctre::phoenix::ErrorCode TalonSRX::ConfigContinuousCurrentLimit(int amps, int timeoutMs) {
	return c_MotController_ConfigContinuousCurrentLimit(m_handle, amps, timeoutMs);
}
/**
 * Enable or disable Current Limit.
 * @param enable
 *            Enable state of current limit.
 * @see ConfigPeakCurrentLimit()
 * @see ConfigPeakCurrentDuration() 
 * @see ConfigContinuousCurrentLimit()
 */
void TalonSRX::EnableCurrentLimit(bool enable) {
	c_MotController_EnableCurrentLimit(m_handle, enable);
}

/**
 * @return object that can get/set individual raw sensor values.
 */
ctre::phoenix::motorcontrol::SensorCollection & TalonSRX::GetSensorCollection() {
	return *_sensorColl;
}

ErrorCode TalonSRX::ConfigurePID(const TalonSRXPIDSetConfiguration &pid, int pidIdx, int timeoutMs, bool enableOptimizations) {

    ErrorCollection errorCollection;
    
    //------ sensor selection ----------//		
   
    if(TalonSRXPIDSetConfigUtil::SelectedFeedbackCoefficientDifferent(pid) || !enableOptimizations)
		errorCollection.NewError(ConfigSelectedFeedbackCoefficient(pid.selectedFeedbackCoefficient, pidIdx, timeoutMs));
	if(TalonSRXPIDSetConfigUtil::SelectedFeedbackSensorDifferent(pid) || !enableOptimizations)
		errorCollection.NewError(ConfigSelectedFeedbackSensor(pid.selectedFeedbackSensor, pidIdx, timeoutMs));
    	
    return errorCollection._worstError;
}
/**
 * Gets all PID set persistant settings (overloaded so timeoutMs is 50 ms
 * and pidIdx is 0).
 *
 * @param pid               Object with all of the PID set persistant settings
 */
void TalonSRX::GetPIDConfigs(TalonSRXPIDSetConfiguration &pid, int pidIdx, int timeoutMs)
{
	BaseGetPIDConfigs(pid, pidIdx, timeoutMs);
	pid.selectedFeedbackSensor = (FeedbackDevice)(int) ConfigGetParameter(eFeedbackSensorType, pidIdx, timeoutMs);

}

/**
 * Configures all peristant settings.
 *
 * @param allConfigs        Object with all of the persistant settings
 * @param timeoutMs
 *              Timeout value in ms. If nonzero, function will wait for
 *              config success and report an error if it times out.
 *              If zero, no blocking or checking is performed.
 *
 * @return Error Code generated by function. 0 indicates no error. 
 */
ErrorCode TalonSRX::ConfigAllSettings(const TalonSRXConfiguration &allConfigs, int timeoutMs) {
    
    ErrorCollection errorCollection;
    
	errorCollection.NewError(BaseConfigAllSettings(allConfigs, timeoutMs));	
   

	//--------PIDs---------------//
	errorCollection.NewError(ConfigurePID(allConfigs.primaryPID, 0, timeoutMs, allConfigs.enableOptimizations));
	errorCollection.NewError(ConfigurePID(allConfigs.auxiliaryPID, 1, timeoutMs, allConfigs.enableOptimizations));
	if(TalonConfigUtil::ForwardLimitSwitchDifferent(allConfigs))
		errorCollection.NewError(c_MotController_ConfigForwardLimitSwitchSource(m_handle, allConfigs.forwardLimitSwitchSource,
			allConfigs.forwardLimitSwitchNormal, allConfigs.forwardLimitSwitchDeviceID, timeoutMs));
	if(TalonConfigUtil::ReverseLimitSwitchDifferent(allConfigs)) 
		errorCollection.NewError(c_MotController_ConfigReverseLimitSwitchSource(m_handle, allConfigs.reverseLimitSwitchSource,
			allConfigs.reverseLimitSwitchNormal, allConfigs.reverseLimitSwitchDeviceID, timeoutMs));
	
	if(TalonConfigUtil::Sum0TermDifferent(allConfigs)) errorCollection.NewError(ConfigSensorTerm(SensorTerm::SensorTerm_Sum0, allConfigs.sum0Term, timeoutMs));
	if(TalonConfigUtil::Sum1TermDifferent(allConfigs)) errorCollection.NewError(ConfigSensorTerm(SensorTerm::SensorTerm_Sum1, allConfigs.sum1Term, timeoutMs));
	if(TalonConfigUtil::Diff0TermDifferent(allConfigs)) errorCollection.NewError(ConfigSensorTerm(SensorTerm::SensorTerm_Diff0, allConfigs.diff0Term, timeoutMs));
	if(TalonConfigUtil::Diff1TermDifferent(allConfigs)) errorCollection.NewError(ConfigSensorTerm(SensorTerm::SensorTerm_Diff1, allConfigs.diff1Term, timeoutMs));
	
	if(TalonConfigUtil::PeakCurrentLimitDifferent(allConfigs)) errorCollection.NewError(ConfigPeakCurrentLimit(allConfigs.peakCurrentLimit, timeoutMs));
	if(TalonConfigUtil::PeakCurrentDurationDifferent(allConfigs)) errorCollection.NewError(ConfigPeakCurrentDuration(allConfigs.peakCurrentDuration, timeoutMs));
	if(TalonConfigUtil::ContinuousCurrentLimitDifferent(allConfigs)) errorCollection.NewError(ConfigContinuousCurrentLimit(allConfigs.continuousCurrentLimit, timeoutMs));

    return errorCollection._worstError;
}
/**
 * Gets all persistant settings.
 *
 * @param allConfigs        Object with all of the persistant settings
 * @param timeoutMs
 *              Timeout value in ms. If nonzero, function will wait for
 *              config success and report an error if it times out.
 *              If zero, no blocking or checking is performed.
 */
void TalonSRX::GetAllConfigs(TalonSRXConfiguration &allConfigs, int timeoutMs) {
	
	BaseGetAllConfigs(allConfigs, timeoutMs);
	
	GetPIDConfigs(allConfigs.primaryPID, 0, timeoutMs);
	GetPIDConfigs(allConfigs.auxiliaryPID, 1, timeoutMs);
    allConfigs.sum0Term = (FeedbackDevice)(int) ConfigGetParameter(eSensorTerm, 0, timeoutMs);
    allConfigs.sum1Term = (FeedbackDevice)(int) ConfigGetParameter(eSensorTerm, 1, timeoutMs);
    allConfigs.diff0Term = (FeedbackDevice)(int) ConfigGetParameter(eSensorTerm, 2, timeoutMs);
    allConfigs.diff1Term = (FeedbackDevice)(int) ConfigGetParameter(eSensorTerm, 3, timeoutMs);


	allConfigs.forwardLimitSwitchSource = (LimitSwitchSource)(int) ConfigGetParameter(eLimitSwitchSource, 0, timeoutMs);
	allConfigs.reverseLimitSwitchSource = (LimitSwitchSource)(int) ConfigGetParameter(eLimitSwitchSource, 1, timeoutMs);
	allConfigs.forwardLimitSwitchDeviceID = (int) ConfigGetParameter(eLimitSwitchRemoteDevID, 0, timeoutMs);
	allConfigs.reverseLimitSwitchDeviceID = (int) ConfigGetParameter(eLimitSwitchRemoteDevID, 1, timeoutMs);
	allConfigs.forwardLimitSwitchNormal = (LimitSwitchNormal)(int) ConfigGetParameter(eLimitSwitchNormClosedAndDis, 0, timeoutMs);
	allConfigs.reverseLimitSwitchNormal = (LimitSwitchNormal)(int) ConfigGetParameter(eLimitSwitchNormClosedAndDis, 1, timeoutMs);
	allConfigs.peakCurrentLimit        = (int) ConfigGetParameter(ePeakCurrentLimitAmps, 0, timeoutMs);
	allConfigs.peakCurrentDuration     = (int) ConfigGetParameter(ePeakCurrentLimitMs, 0, timeoutMs);
	allConfigs.continuousCurrentLimit  = (int) ConfigGetParameter(eContinuousCurrentLimitAmps, 0, timeoutMs); 

}
