% 1. Extraer los arreglos numéricos de los objetos timeseries
x_data = out.BicyclePose.x.Data(:);
y_data = out.BicyclePose.y.Data(:);
theta_data = out.BicyclePose.theta.Data(:);

% 2. Reconstruir la matriz original [X, Y, Theta]
poseMatrix = [x_data, y_data, theta_data];

numRobots = size(poseMatrix, 2) / 3;
thetaIdx = 3;
map = binaryOccupancyMap(simpleMap);

% Translation
xyz = poseMatrix;
xyz(:, thetaIdx) = 0; 

% Rotation in XYZ euler angles
theta = poseMatrix(:, thetaIdx);
thetaEuler = zeros(size(poseMatrix, 1), 3 * size(theta, 2));
thetaEuler(:, end) = theta;

for k = 1:size(xyz, 1)
    show(map)
    hold on;
    
    % Plot Start Location
    plotTransforms([startLoc, 0], eul2quat([0, 0, 0]))
    text(startLoc(1), startLoc(2), 2, 'Start');
    
    % Plot Goal Location
    plotTransforms([goalLoc, 0], eul2quat([0, 0, 0]))
    text(goalLoc(1), goalLoc(2), 2, 'Goal');
    
    % Plot Robot's XY locations
    plot(poseMatrix(:, 1), poseMatrix(:, 2), '-b')
    
    % Plot Robot's pose as it traverses the path
    quat = eul2quat(thetaEuler(k, :), 'xyz');
    plotTransforms(xyz(k,:), quat, 'MeshFilePath', 'groundvehicle.stl');
    
    pause(0.0001)
    hold off;
end