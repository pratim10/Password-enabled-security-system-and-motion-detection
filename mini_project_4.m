answer=123; % this is where we'll store the user's answer
arduino=serial('COM5','BaudRate',9600); % create serial communication object on port COM5
 
fopen(arduino); % initiate arduino communication
 
while answer
    fprintf(arduino,'%s',answer); % send answer variable content to arduino
    answer=input('ENTER  PASSWORD  : '); % ask user to enter Password
end
 
fclose(arduino); % end communication with arduino