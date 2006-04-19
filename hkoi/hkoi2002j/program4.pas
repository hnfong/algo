program test;
var
	fp: text;
	a : array [1..33000] of integer;
	n : longint;

procedure readinput;
var
	i,j,k,t:longint;
begin
	for i := 1 to 30000 do begin
		a[i] := 0;
	end;
	assign(fp, 'input4.txt');
	reset(fp);
	readln(fp, n);
	for i := 1 to n do begin
		readln(fp, t);
		a[t] := a[t] + 1;
	end;
	close(fp);
end;

procedure mean;
var
	i,j,k,t: longint;
begin
	for i := 1 to 33000 do begin
		t := t + (i * a[i]);
	end;
	writeln(t/n : 0 : 3);
end;

procedure mode;
var
	i,j,k,t : longint;
begin
	t := 0;
	for i := 1 to 33000 do begin
		if a[i] > t then begin 
			t := a[i];
			k := i;
		end;
	end;
	writeln(k);
end;

procedure median;
var
	i,j,k,t : longint;
begin
	t := 0;
	k := 0;
	for i := 1 to 33000 do begin
		t := t + a[i];
		if t >= (n div 2) then begin
			if (n mod 2) = 1 then
				writeln(i)
			else begin
				if t = (n div 2) then
					for j := i to 33000 do begin
						if a[j] > 0 then begin writeln((i + j)/2:0:1); break ; end;
					end;
				if t > n div 2 then
					writeln(i);
			end;
			break;
		end;
	end;
end;

procedure dumplist;
var
	i,j,k,t : longint;
	b : array [1..30000] of integer;
begin
	j := 0;
	for i := 1 to n do begin
		for k := j to a[i] do begin
			writeln(i);
		end;
	end;
end;
begin
	readinput;
{	mean;
	mode;
	median;}
	dumplist;
end.

