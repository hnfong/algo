program p371;
{
	@JUDGE_ID:  20044WC 371 PASCAL "DyP"
}
const
	lim = 1000000;
var
	min : longword;
	max : longword;
	i,j : longword;
	a : array[1..lim] of integer;
	maxval : longint;
	maxi : longint;
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
	while true do begin
		read(min, max);
		if (max = 0) and (min = 0) then break;
		if (min < 0) or (max < 0) then continue;
		if (max < min) then begin
			t := max;
			max := min;
			min := t;
		end;
		maxval := 0;
		maxi := 0;
		for i := min to max-1 do begin
			if maxval < len(i) then begin maxval := len(i); maxi := i; end;
		end;
		writeln('Between ', min:0, ' and ', max:0, ', ', maxi:0, ' generates the longest sequence of ', (maxval - 1):0, ' values.');
	end;
end.

