program p100;
{
	@JUDGE_ID:  20044WC 100 PASCAL "Dynamic Programming"
}
const
	lim = 1000000;
var
	min : longword;
	max : longword;
	i,j : longword;
	a : array[1..lim] of integer;
	maxval : longint;
	t : longword;

function len (x : longword) : longint;
begin
	if (x <= lim) then
		if (a[x] > 0) then begin
			len := a[x];
			exit;
		end;
	if x = 1 then begin
		len := 1;
		exit;
	end;
	if (x mod 2) = 1 then begin
		if (x <= lim) then begin
			a[x] := len((x*3+1) div 2) + 2;
			len := a[x];
			exit;
		end else begin
			len := len((x*3+1) div 2) + 2;
			exit;
		end;
	end else begin
		if (x <= lim) then begin
			a[x] := len(x div 2) + 1;
			len := a[x];
			exit;
		end else begin
			len := len(x div 2) + 1;
			exit;
		end;
	end;
end;

begin
	fillchar(a, lim, 0);
	while (not eof(input)) do begin
		read(min);
		readln(max);
		t := 0;
		if (max < min) then begin
			t := max;
			max := min;
			min := t;
		end;
		maxval := 0;
		for i := min to max do begin
			if maxval < len(i) then maxval := len(i);
		end;
		if (t > 0) then begin
			t := max;
			max := min;
			min := t;
		end;
		writeln(min, ' ', max, ' ', maxval);
	end;
end.

