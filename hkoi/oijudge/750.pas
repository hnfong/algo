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
	for mi := 1 to 1 do begin
		nummap := 0;
		readln(y,x);
		put (1);
	end;
end.

