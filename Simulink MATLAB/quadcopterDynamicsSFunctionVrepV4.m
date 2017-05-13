function quadcopterDynamicsSFunction(block)
setup(block);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% quadcopter dynamic equations%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


% Function: setup ===================================================
% Abstract:
%   Set up the S-function block's basic characteristics such as:
%   - Input ports
%   - Output ports
%   - Dialog parameters
%   - Options
% 
%   Required         : Yes
%   C-Mex counterpart: mdlInitializeSizes
%
function setup(block)

  % Register the number of ports.
  %------
  block.NumInputPorts  = 5;
  %------
  block.NumOutputPorts = 12;
  
  % Set up the port properties to be inherited or dynamic.
  
  for i = 1:4; % These are the motor inputs
  block.InputPort(i).Dimensions        = 1;
  block.InputPort(i).DirectFeedthrough = false;
  block.InputPort(i).SamplingMode      = 'Sample';
  end
  %------
  % This is the disturbance input
  block.InputPort(5).Dimensions        = 6; % torques x,y,z; forces x,y,z.
  block.InputPort(5).DirectFeedthrough = false;
  block.InputPort(5).SamplingMode      = 'Sample';
  %------
  for i = 1:12;
  block.OutputPort(i).Dimensions       = 1;
  block.OutputPort(i).SamplingMode     = 'Sample';
  end

%   % Override the input port properties.
%   block.InputPort(1).DatatypeID  = 0;  % double
%   block.InputPort(1).Complexity  = 'Real';
%   
%   % Override the output port properties.
%   block.OutputPort(1).DatatypeID  = 0; % double
%   block.OutputPort(1).Complexity  = 'Real';

  % Register the parameters.
  block.NumDialogPrms     = 2;
  
  % Set up the continuous states.
  block.NumContStates = 12;

  % Register the sample times.
  %  [0 offset]            : Continuous sample time
  %  [positive_num offset] : Discrete sample time
  %
  %  [-1, 0]               : Inherited sample time
  %  [-2, 0]               : Variable sample time
  block.SampleTimes = [0 0];
  
  % -----------------------------------------------------------------
  % Options
  % -----------------------------------------------------------------
  % Specify if Accelerator should use TLC or call back to the 
  % MATLAB file
  block.SetAccelRunOnTLC(false);
  
  % Specify the block simStateCompliance. The allowed values are:
  %    'UnknownSimState', < The default setting; warn and assume DefaultSimState
  %    'DefaultSimState', < Same SimState as a built-in block
  %    'HasNoSimState',   < No SimState
  %    'CustomSimState',  < Has GetSimState and SetSimState methods
  %    'DisallowSimState' < Errors out when saving or restoring the SimState
  block.SimStateCompliance = 'DefaultSimState';
  
  % -----------------------------------------------------------------
  % The MATLAB S-function uses an internal registry for all
  % block methods. You should register all relevant methods
  % (optional and required) as illustrated below. You may choose
  % any suitable name for the methods and implement these methods
  % as local functions within the same file.
  % -----------------------------------------------------------------
   
  % -----------------------------------------------------------------
  % Register the methods called during update diagram/compilation.
  % -----------------------------------------------------------------
  
%   % 
%   % CheckParameters:
%   %   Functionality    : Called in order to allow validation of the
%   %                      block dialog parameters. You are 
%   %                      responsible for calling this method
%   %                      explicitly at the start of the setup method.
%   %   C-Mex counterpart: mdlCheckParameters
%   %
   block.RegBlockMethod('CheckParameters', @CheckPrms);

%   %
%   % SetInputPortSamplingMode:
%   %   Functionality    : Check and set input and output port 
%   %                      attributes and specify whether the port is operating 
%   %                      in sample-based or frame-based mode
%   %   C-Mex counterpart: mdlSetInputPortFrameData.
%   %   (The DSP System Toolbox is required to set a port as frame-based)
%   %
%   block.RegBlockMethod('SetInputPortSamplingMode', @SetInpPortFrameData);
  
%   %
%   % SetInputPortDimensions:
%   %   Functionality    : Check and set the input and optionally the output
%   %                      port dimensions.
%   %   C-Mex counterpart: mdlSetInputPortDimensionInfo
%   %
%   block.RegBlockMethod('SetInputPortDimensions', @SetInpPortDims);

%   %
%   % SetOutputPortDimensions:
%   %   Functionality    : Check and set the output and optionally the input
%   %                      port dimensions.
%   %   C-Mex counterpart: mdlSetOutputPortDimensionInfo
%   %
%   block.RegBlockMethod('SetOutputPortDimensions', @SetOutPortDims);
  
%   %
%   % SetInputPortDatatype:
%   %   Functionality    : Check and set the input and optionally the output
%   %                      port datatypes.
%   %   C-Mex counterpart: mdlSetInputPortDataType
%   %
%   block.RegBlockMethod('SetInputPortDataType', @SetInpPortDataType);
  
%   %
%   % SetOutputPortDatatype:
%   %   Functionality    : Check and set the output and optionally the input
%   %                      port datatypes.
%   %   C-Mex counterpart: mdlSetOutputPortDataType
%   %
%   block.RegBlockMethod('SetOutputPortDataType', @SetOutPortDataType);
  
%   %
%   % SetInputPortComplexSignal:
%   %   Functionality    : Check and set the input and optionally the output
%   %                      port complexity attributes.
%   %   C-Mex counterpart: mdlSetInputPortComplexSignal
%   %
%   block.RegBlockMethod('SetInputPortComplexSignal', @SetInpPortComplexSig);
%   
%   %
%   % SetOutputPortComplexSignal:
%   %   Functionality    : Check and set the output and optionally the input
%   %                      port complexity attributes.
%   %   C-Mex counterpart: mdlSetOutputPortComplexSignal
%   %
%   block.RegBlockMethod('SetOutputPortComplexSignal', @SetOutPortComplexSig);
  
%   %
%   % PostPropagationSetup:
%   %   Functionality    : Set up the work areas and the state variables. You can
%   %                      also register run-time methods here.
%   %   C-Mex counterpart: mdlSetWorkWidths
%   %
%   block.RegBlockMethod('PostPropagationSetup', @DoPostPropSetup);
% 
%   % -----------------------------------------------------------------
%   % Register methods called at run-time
%   % -----------------------------------------------------------------
%   
%   % 
%   % ProcessParameters:
%   %   Functionality    : Call to allow an update of run-time parameters.
%   %   C-Mex counterpart: mdlProcessParameters
%   %  
%   block.RegBlockMethod('ProcessParameters', @ProcessPrms);

  % 
  % InitializeConditions:
  %   Functionality    : Call to initialize the state and the work
  %                      area values.
  %   C-Mex counterpart: mdlInitializeConditions
  % 
  block.RegBlockMethod('InitializeConditions', @InitializeConditions);
  
%   % 
%   % Start:
%   %   Functionality    : Call to initialize the state and the work
%   %                      area values.
%   %   C-Mex counterpart: mdlStart
%   %
%   block.RegBlockMethod('Start', @Start);

  % 
  % Outputs:
  %   Functionality    : Call to generate the block outputs during a
  %                      simulation step.
  %   C-Mex counterpart: mdlOutputs
  %
  block.RegBlockMethod('Outputs', @Outputs);

%   % 
%   % Update:
%   %   Functionality    : Call to update the discrete states
%   %                      during a simulation step.
%   %   C-Mex counterpart: mdlUpdate
%   %
%   block.RegBlockMethod('Update', @Update);

  % 
  % Derivatives:
  %   Functionality    : Call to update the derivatives of the
  %                      continuous states during a simulation step.
  %   C-Mex counterpart: mdlDerivatives
  %
  block.RegBlockMethod('Derivatives', @Derivatives);
  
%   % 
%   % Projection:
%   %   Functionality    : Call to update the projections during a
%   %                      simulation step.
%   %   C-Mex counterpart: mdlProjections
%   %
%   block.RegBlockMethod('Projection', @Projection);
  
%   % 
%   % SimStatusChange:
%   %   Functionality    : Call when simulation enters pause mode
%   %                      or leaves pause mode.
%   %   C-Mex counterpart: mdlSimStatusChange
%   %
%   block.RegBlockMethod('SimStatusChange', @SimStatusChange);
%   
%   % 
%   % Terminate:
%   %   Functionality    : Call at the end of a simulation for cleanup.
%   %   C-Mex counterpart: mdlTerminate
%   %
%   block.RegBlockMethod('Terminate', @Terminate);

%   %
%   % GetSimState:
%   %   Functionality    : Return the SimState of the block.
%   %   C-Mex counterpart: mdlGetSimState
%   %
%   block.RegBlockMethod('GetSimState', @GetSimState);
%   
%   %
%   % SetSimState:
%   %   Functionality    : Set the SimState of the block using a given value.
%   %   C-Mex counterpart: mdlSetSimState
%   %
%   block.RegBlockMethod('SetSimState', @SetSimState);

  % -----------------------------------------------------------------
  % Register the methods called during code generation.
  % -----------------------------------------------------------------
  
%   %
%   % WriteRTW:
%   %   Functionality    : Write specific information to model.rtw file.
%   %   C-Mex counterpart: mdlRTW
%   %
%   block.RegBlockMethod('WriteRTW', @WriteRTW);
% %endfunction

% -------------------------------------------------------------------
% The local functions below are provided to illustrate how you may implement
% the various block methods listed above.
% -------------------------------------------------------------------

 function CheckPrms(block)
     quad   = block.DialogPrm(1).Data;
     IC     = block.DialogPrm(2).Data;
%      if ~exist(model)
%        me = MSLException(block.BlockHandle, message('Simulink:blocks:invalidParameter'));
%        throw(me);
%      end
     
%     if ~strcmp(class(a), 'double')
%       me = MSLException(block.BlockHandle, message('Simulink:blocks:invalidParameter'));
%       throw(me);
%     end
% %endfunction
% 
% function ProcessPrms(block)
% 
%   block.AutoUpdateRuntimePrms;
%  
% %endfunction
% 
% function SetInpPortFrameData(block, idx, fd)
%   
%   block.InputPort(idx).SamplingMode = fd;
%   block.OutputPort(1).SamplingMode  = fd;
%   
% %endfunction
% 
% function SetInpPortDims(block, idx, di)
%   
%   block.InputPort(idx).Dimensions = di;
%   block.OutputPort(1).Dimensions  = di;
% 
% %endfunction
% 
% function SetOutPortDims(block, idx, di)
%   
%   block.OutputPort(idx).Dimensions = di;
%   block.InputPort(1).Dimensions    = di;
% 
% %endfunction
% 
% function SetInpPortDataType(block, idx, dt)
%   
%   block.InputPort(idx).DataTypeID = dt;
%   block.OutputPort(1).DataTypeID  = dt;
% 
% %endfunction
%   
% function SetOutPortDataType(block, idx, dt)
% 
%   block.OutputPort(idx).DataTypeID  = dt;
%   block.InputPort(1).DataTypeID     = dt;
% 
% %endfunction  
% 
% function SetInpPortComplexSig(block, idx, c)
%   
%   block.InputPort(idx).Complexity = c;
%   block.OutputPort(1).Complexity  = c;
% 
% %endfunction 
%   
% function SetOutPortComplexSig(block, idx, c)
% 
%   block.OutputPort(idx).Complexity = c;
%   block.InputPort(1).Complexity    = c;
% 
% %endfunction 
%     
% function DoPostPropSetup(block)
%
%   block.NumDworks = 2;
%   
%   block.Dwork(1).Name            = 'x1';
%   block.Dwork(1).Dimensions      = 1;
%   block.Dwork(1).DatatypeID      = 0;      % double
%   block.Dwork(1).Complexity      = 'Real'; % real
%   block.Dwork(1).UsedAsDiscState = true;
%   
%   block.Dwork(2).Name            = 'numPause';
%   block.Dwork(2).Dimensions      = 1;
%   block.Dwork(2).DatatypeID      = 7;      % uint32
%   block.Dwork(2).Complexity      = 'Real'; % real
%   block.Dwork(2).UsedAsDiscState = true;
%   
%   % Register all tunable parameters as runtime parameters.
%   block.AutoRegRuntimePrms;
% 
% %endfunction

function InitializeConditions(block)
% Initialize 12 States

IC = block.DialogPrm(2).Data;

% IC.P, IC.Q, IC.R are in deg/s ... convert to rad/s
P = IC.P*pi/180; Q = IC.Q*pi/180; R = IC.R*pi/180; 
% IC.Phi, IC.The, IC.Psi are in deg ... convert to rads
Phi = IC.Phi*pi/180; The = IC.The*pi/180; Psi = IC.Psi*pi/180;
U = IC.U; V = IC.V; W = IC.W; 
X = IC.X; Y = IC.Y; Z = IC.Z;

init = [P,Q,R,Phi,The,Psi,U,V,W,X,Y,Z];
for i=1:12
block.OutputPort(i).Data = init(i);
block.ContStates.Data(i) = init(i);
end

% function Start(block)
% 
%   block.Dwork(1).Data = 0;
%   block.Dwork(2).Data = uint32(1); 
%    
% %endfunction
% 
% function WriteRTW(block)
%   
%    block.WriteRTWParam('matrix', 'M',    [1 2; 3 4]);
%    block.WriteRTWParam('string', 'Mode', 'Auto');
   
%endfunction

function Outputs(block)
for i = 1:12;
  block.OutputPort(i).Data = block.ContStates.Data(i);
end

%endfunction

% function Update(block)
%   
%   block.Dwork(1).Data = block.InputPort(1).Data;
  
%endfunction

function Derivatives(block)
% Name all the states and motor inputs

% Load model data selected in parameter block
%which('model')

quad = block.DialogPrm(1).Data;

% P Q R in units of rad/sec
% P = block.ContStates.Data(1);
% Q = block.ContStates.Data(2);
% R = block.ContStates.Data(3);
% % Phi The Psi in radians
% Phi = block.ContStates.Data(4);
% The = block.ContStates.Data(5);
% Psi = block.ContStates.Data(6);
% % U V W in units of m/s
% U = block.ContStates.Data(7);
% V = block.ContStates.Data(8);
% W = block.ContStates.Data(9);
% % X Y Z in units of m
% X = block.ContStates.Data(10);
% Y = block.ContStates.Data(11);
% Z = block.ContStates.Data(12);
% w values in rev/min! NOT radians/s!!!!
w1 = block.InputPort(1).Data;
w2 = block.InputPort(2).Data;
w3 = block.InputPort(3).Data;
w4 = block.InputPort(4).Data;
%w  = [w1; w2; w3; w4];

ww=[w1 w2 w3 w4];


%VREP Connection

vrep=remApi('remoteApi'); % using the prototype file (remoteApiProto.m)
vrep.simxFinish(-1); % just in case, close all opened connections
clientID=vrep.simxStart('127.0.0.1',19997,true,true,5000,5);
%[returnCode,position]=vrep.simxGetStringSignal(clientID,'Position',vrep.simx_opmode_streaming);
%[returnCode,angle]=vrep.simxGetStringSignal(clientID,'Angle',vrep.simx_opmode_streaming);
%[returnCode,velocities]=vrep.simxGetStringSignal(clientID,'Velocities',vrep.simx_opmode_streaming);
%[returnCode,st]=vrep.simxGetStringSignal(clientID,'W',vrep.simx_opmode_streaming);
[returnCode,StateData]=vrep.simxGetStringSignal(clientID,'StateData',vrep.simx_opmode_streaming);
    if (clientID>-1)
%     disp('Connected to remote API server');
    vrep.simxSynchronous(clientID,true);
    vrep.simxStartSimulation(clientID,vrep.simx_opmode_oneshot);
       
    for i=0:1
    
    %vrep.simxSynchronousTrigger(clientID); 
    %vrep.simxGetPingTime(clientID);
    st=vrep.simxPackFloats(ww);
    error=vrep.simxSetStringSignal(clientID,'W',st,vrep.simx_opmode_oneshot);
    %vrep.simxSynchronousTrigger(clientID); 
    
    %error=vrep.simxSetStringSignal(clientID,'W',st,vrep.simx_opmode_discontinue);
    %error=vrep.simxSetFloatSignal(clientID,'w1',w1,vrep.simx_opmode_oneshot);
    %vrep.simxSynchronousTrigger(clientID); 
        %if(returnCode==vrep.simx_return_ok)
        %[err,position]=vrep.simxGetStringSignal(clientID,'Position',vrep.simx_opmode_buffer);
        %[err,angle]=vrep.simxGetStringSignal(clientID,'Angle',vrep.simx_opmode_buffer);
        %[err,velocities]=vrep.simxGetStringSignal(clientID,'Velocities',vrep.simx_opmode_buffer);
        %[err,avelocities]=vrep.simxGetStringSignal(clientID,'aVelocities',vrep.simx_opmode_buffer);
        [err,StateData]=vrep.simxGetStringSignal(clientID,'StateData',vrep.simx_opmode_buffer);
        vrep.simxSynchronousTrigger(clientID);
        %pos=vrep.simxUnpackFloats(position)
        %ang=vrep.simxUnpackFloats(angle)
        %vel=vrep.simxUnpackFloats(velocities)
        %avel=vrep.simxUnpackFloats(avelocities)
        
    end
        
        SD=vrep.simxUnpackFloats(StateData);
  %end
  
  
  
        block.ContStates.Data(1) = SD(1);%*pi/180;
        block.ContStates.Data(2) = SD(2);%*pi/180;
        block.ContStates.Data(3) = SD(3);%*pi/180;
        block.ContStates.Data(4) = SD(4);%*pi/180;
        block.ContStates.Data(5) = SD(5);%*pi/180;
        block.ContStates.Data(6) = SD(6);%*pi/180;
        block.ContStates.Data(7) = SD(7);
        block.ContStates.Data(8) = SD(8);
        block.ContStates.Data(9) = SD(9);
        block.ContStates.Data(10) = SD(10);
        block.ContStates.Data(11) = SD(11);
        block.ContStates.Data(12) = SD(12);

        %vrep.simxSynchronousTrigger(clientID);

       
  
    
    
    else
        disp('Failed connecting to remote API server');
    end

    

%------
Dist_tau = block.InputPort(5).Data(1:3);
Dist_F   = block.InputPort(5).Data(4:6);
%------

% CALCULATE MOMENT AND THRUST FORCES
% Total Moment due to motor speeds
% Moment should be in units of N*m
% The experimental determination of Ct and Cq should be adjusted to
% model using kg instead of ounces or lb
% Mb = (quad.dctcq*(w.^2)) + (Dist_tau);  %(dctcq*(w.^2)); % Mb = [tau1 tau2 tau3]'
%  tau_motorGyro = [Q*quad.Jm*2*pi/60*(-w1-w3+w2+w4); P*quad.Jm*2*pi/60*(w1+w3-w2-w4); 0]; % Note: 2*pi/60 required to convert from RPM to radians/s
%  Mb = (quad.dctcq*(w.^2))+ tau_motorGyro + (Dist_tau);  % Mb = [tau1 tau2 tau3]'
% 
% % Thrust due to motor speed
% % Force should be in units of Newtons for simplicity in calculating
% % the acceleration in the angular velocity state equation
% Fb = [0; 0; sum(quad.ct*(w.^2))];   %[0, 0, sum(ct*w.^2)]'
% 
% % Obtain dP dQ dR
% omb_bi = [P; Q; R];
% OMb_bi = [ 0,-R, Q;
%            R, 0,-P;
%           -Q, P, 0];
% 
% b_omdotb_bi = quad.Jbinv*(Mb-OMb_bi*quad.Jb*omb_bi);
% H_Phi = [1,tan(The)*sin(Phi), tan(The)*cos(Phi);
%          0,         cos(Phi),         -sin(Phi);
%          0,sin(Phi)/cos(The),cos(Phi)/cos(The)];   
% Phidot = H_Phi*omb_bi;

% Compute Rotation Matrix
% We use a Z-Y-X rotation
% % Rib = [cos(Psi)*cos(The) cos(Psi)*sin(The)*sin(Phi)-sin(Psi)*cos(Phi) cos(Psi)*sin(The)*cos(Phi)+sin(Psi)*sin(Phi);
% %        sin(Psi)*cos(The) sin(Psi)*sin(The)*sin(Phi)+cos(Psi)*cos(Phi) sin(Psi)*sin(The)*cos(Phi)-cos(Psi)*sin(Phi);
% %        -sin(The)         cos(The)*sin(Phi)                            cos(The)*cos(Phi)];
% % Rbi = Rib';
% % ge = [0; 0; -quad.g];
% % gb = Rbi*ge;
% % Dist_Fb = Rbi*Dist_F;
% % 
% % % Compute Velocity and Position derivatives of body frame
% % vb = [U;V;W];
% % b_dv = (1/quad.mass)*Fb+gb+Dist_Fb-OMb_bi*vb; % Acceleration in body frame (FOR VELOCITY)
% % i_dp = Rib*vb; % Units OK SI: Velocity of body frame w.r.t inertia frame (FOR POSITION)

% dP = SD(1);%*pi/180;%b_omdotb_bi(1);
% dQ = SD(2);%*pi/180;%b_omdotb_bi(2);
% dR = SD(3);%*pi/180;%b_omdotb_bi(3);
% dPhi = SD(4);%*pi/180;%Phidot(1);
% dTheta = SD(5);%*pi/180;%Phidot(2);
% dPsi = SD(6);%*pi/180;%Phidot(3);
% dU = SD(7);%b_dv(1);
% dV = SD(8);%b_dv(2);
% dW = SD(9);%b_dv(3);
% dX = SD(10);%i_dp(1);
% dY =SD(11);%i_dp(2);
% dZ = SD(12);%i_dp(3);

% % Rough rule to impose a "ground" boundary...could easily be improved...
% %if ((Z<=0) && (dZ<=0)) % better  version then before?
%  %   dZ = 0;
%    
% %end
% %f = [dP dQ dR dPhi dTheta dPsi dU dV dW dX dY dZ].';
% %block.Derivatives.Data=f;

%   %This is the state derivative vector
% block.Derivatives.Data(1)=dP;
% block.Derivatives.Data(2)=dQ;
% block.Derivatives.Data(3)=dR;
% block.Derivatives.Data(4)=dPhi;
% block.Derivatives.Data(5)=dTheta;
% block.Derivatives.Data(6)=dPsi;
% block.Derivatives.Data(7)=dU;
% block.Derivatives.Data(8)=dV;
% block.Derivatives.Data(9)=dW;
% block.Derivatives.Data(10)=dX;
% block.Derivatives.Data(11)=dY;
% block.Derivatives.Data(12)=dZ;



%endfunction