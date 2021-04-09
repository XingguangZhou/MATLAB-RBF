clc;
clear;

ERR = 1E-12;

A = rand(5, 5);
B = A;

C = zeros(size(A, 1), size(B, 2));

sum = 0.0;

% matrix multiplication
for i = 1:size(A, 1)
    for j = 1:size(B, 2)
        sum = 0.0;
        for k =1:size(A, 1)
            sum = sum + A(i, k) * B(k, j);
        end
        C(i, j) = sum;
    end
end

disp(C);

result = A*B;

flag = 1;
% make the verfication
for i = 1:size(C, 1)
    for j = 1:size(C, 2)
        if abs(result(i, j) - C(i, j)) >= ERR
            flag = 0;
            disp(['the element is : ', num2str(result(i, j)), '  index(', num2str(i), ',', num2str(j), ')']);
        end
    end
end

if flag == 1
    disp('Equal!');
elseif flag == 0
    disp('Do not equal!');
end