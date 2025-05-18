program p1027;
const
	siz = 10000;
	digit = 100000;
	pw : array[1..4] of integer = (10,100,1000,10000);
var	
	i,j,k,n,t : longint;
	w : array[1..siz] of longint;
	estsize : double;
procedure nwrite(x : longint);
var i : byte;
begin
	for i := 4 downto 1 do begin
		if x div pw[i] = 0 then write(0);
	end;
	write(x);
end;
procedure xwrite(x : longint);
begin
	if x = 0 then exit;
	write(x);
end;

begin
	readln(n);
	fillchar(w,sizeof(w),0);
	w[1] := 1;
	for i := 2 to n do begin
		estsize := estsize + (ln(i)/ln(digit));
		for j := 1 to trunc(estsize)+2 do begin
			w[j] := w[j] * i;
		end;
		for j := 1 to trunc(estsize)+2 do begin
			w[j+1] := w[j+1] + w[j] div digit;
			w[j] := w[j] mod digit;
		end;
	end;
	
	j := 0;
	for i := siz downto 1 do begin
		if j = 1 then nwrite(w[i]) else xwrite(w[i]);
		if w[i] > 0 then j := 1;
	end;
	writeln;
end.

