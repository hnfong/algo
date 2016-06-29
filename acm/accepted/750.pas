program p750;
{
	@JUDGE_ID:  20044WC 750 PASCAL "Exhaustion... against your will?"
}
var
	a : array [1..8] of longint;
	mn : longint;
	nummap,mi,x,y : longint;

procedure put(l : longint);
var
	i,j,k : longint;
	t : boolean;
begin
	if (l > 8) then begin
		if a[x] = y then begin
			inc(nummap);
			write(nummap:2,'      ');
			for i := 1 to 7 do begin write(a[i], ' '); end;
			writeln(a[8]);
		end;
		exit;
	end;
	for i := 1 to 8 do begin
		t := true;
		{ check vertical clash }
		for j := 1 to 8 do begin
			if (a[j] = i) then t := false;
		end;
		if (t = false) then continue;
		{ check diagonal clash }
		for j := 1 to l-1 do begin
			{ this is slope }
			if (abs(abs((j - l) / (a[j] - i)) - 1) < 0.00001) then  t:= false;
		end;
		if t = true then begin 
			a[l] := i;
			put(l + 1);
			a[l] := 0;
		end;
	end;
end;

begin
	readln(mn);
	for mi := 1 to mn do begin
		nummap := 0;
		readln;
		readln(y,x);
		writeln('SOLN       COLUMN');
		writeln(' #      1 2 3 4 5 6 7 8');
		writeln;
		put (1);
		writeln;
	end;
end.

