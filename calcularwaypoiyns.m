function waypoints = calcularwaypoiyns(startPos, endPos, mapMatrix)

persistent waypointsInternal
persistent prevStartPos
persistent prevEndPos

% Set constant parameters
maxNumNodes = 100;

% Initialize persistent variables that are used downstream
if isempty(prevStartPos)
    prevStartPos = startPos;
end

if isempty(prevEndPos)
    prevEndPos = endPos;
end

isNewPath = (~isequal(prevStartPos, startPos) || ~isequal(prevEndPos, endPos));

if isempty(waypointsInternal) || isNewPath
    % Two conditions in which waypoints must be set: they are not yet
    % initialized, or they are initialized, but the current start and end
    % do not match those used to generate the previous set of waypoints
    [waypointsInternal] = planPath(mapMatrix, maxNumNodes, startPos, endPos);
end

% Update the outputs
waypoints = waypointsInternal;

% Update the persistent variables that indicate previous state
prevStartPos = startPos;
prevEndPos = endPos;

%% Helper Function

function wayPoints = planPath(mapMatrix, maxNodes, startPos, endPos)
    
    % Create a probabilistic roadmap
    map = binaryOccupancyMap(mapMatrix);
    prm = mobileRobotPRM(map, maxNodes);
    
    % Find a path between two points
    xy = findpath(prm, startPos, endPos);
    wayPoints = repmat(endPos, maxNodes, 1);
    
    % Number of nodes that are actually used
    numNodes = length(xy);
    wayPoints(1:numNodes,:) = xy;    

end

end