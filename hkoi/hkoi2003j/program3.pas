program p3;
var
	i : longint;
	n : Longint;
function isprime(a:longint) : boolean;
var
	i,j,k : longint;
begin
	for i := 2 to trunc(sqrt(a)) do begin
		if a mod i = 0 then begin
			isprime := false;
			exit;
		end;
	end;
	isprime := true;
	exit;
end;

begin
	assign(input,'input3.txt');
	reset(input);
	assign(output,'output3.txt');
	rewrite(output);
	while true do begin
		readln(n);
		if n mod 2 = 1 then begin
			if isprime(n-2) then writeln(2,' ',n-2) else writeln('Impossible');
			break;
		end;


		for i := n div 2 downto 2 do begin
			if isprime(i) and isprime(n-i) then begin
				writeln(i, ' ', n-i);
				break;
			end;
		end;
		break;
	end;
	close(output);
	close(input);
end.
