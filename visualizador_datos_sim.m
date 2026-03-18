% 1. Extraer los arreglos numéricos y el vector de tiempo
time_data = out.BicyclePose.x.Time(:); % Se extrae el tiempo para calcular el Ts
x_data = out.BicyclePose.x.Data(:);
y_data = out.BicyclePose.y.Data(:);
theta_data = out.BicyclePose.theta.Data(:);

% Calcular matemáticamente el salto de índices equivalente a 1 segundo
Ts = mean(diff(time_data)); 
paso_1_seg = round(1 / Ts); 

% 2. Reconstruir la matriz original [X, Y, Theta]
robotPose  = [x_data, y_data, theta_data];
thetaIdx = 3;
map = binaryOccupancyMap(simpleMap);

% Translation
xyz = robotPose;
xyz(:, thetaIdx) = 0;

% Rotation in XYZ euler angles
theta = robotPose(:,thetaIdx);
thetaEuler = zeros(size(robotPose, 1), 3 * size(theta, 2));
thetaEuler(:, end) = theta;

% Bucle for modificado iterando con el paso de 1 segundo
for k = 1:paso_1_seg:size(xyz, 1)
    show(map)
    hold on;
    
    % Plot Start Location
    plotTransforms([startLoc, 0], eul2quat([0, 0, 0]))
    text(startLoc(1), startLoc(2), 2, 'Start');
    
    % Plot Goal Location
    plotTransforms([goalLoc, 0], eul2quat([0, 0, 0]))
    text(goalLoc(1), goalLoc(2), 2, 'Goal');
    
    % Plot Robot's XY locations
    plot(robotPose(:, 1), robotPose(:, 2), '-b')
    
    % Plot Robot's pose as it traverses the path
    quat = eul2quat(thetaEuler(k, :), 'xyz');
    plotTransforms(xyz(k,:), quat, 'MeshFilePath',...
        'groundvehicle.stl');
    
    pause(0.01)
    hold off;
end