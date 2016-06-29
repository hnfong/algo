program x784;
{
	@JUDGE_ID:  20044WC 784 PASCAL "Siliconism"
}
type
	coords = record
		x : Longint;
		y : longint;
	end;
var
	q : array[1..2400] of coords;
	qs, qe : longint;
	i,j,k : longint;
	t1,t2 : longint;
	t : coords;
	map : array[0..80] of string;
	n : longint;
	s : string;
	mapw, maph : longint;
procedure dump;
begin
	for j := 1 to maph+1 do begin
		writeln(map[j]);
	end;
end;
procedure pushq(y,x : longint);
var
	co : coords;
begin
	map[y,x] := '#';
	co.x := x;
	co.y := y;
	qe := qe + 1;
	q[qe] := co;
end;

function popq : coords;
begin
	qs := qs + 1;
	popq := q[qs];
end;

begin
	readln(n);

	for k := 1 to n do begin
		for j := 0 to 80 do begin
			map[j] := '';
		end;
		t.x := 0;
		t.y := 0;
		for j := 1 to 2400 do begin
			q[j] := t;
		end;
		{ init }
		qs := 0;
		qe := 0;
		{ input }
		j:=0;
		readln(s);
		mapw := length(s);
		while (s[1] <> '_') do begin
			j := j + 1;
			map[j] := s;
			readln(s);
		end;
		maph := j;
		j := j + 1;
		map[j] := s;

		for j := 1 to maph do if (pos('*', map[j]) > 0) then begin t.x := pos('*', map[j]); t.y := j; end;

		{process}
		pushq(t.y, t.x);
		while (qs <> qe) do begin
			t := popq;
			if map[(t.y + 1), (t.x)] = ' ' then pushq(t.y+1, t.x);
			if map[(t.y - 1), (t.x)] = ' ' then pushq(t.y-1, t.x);
			if map[(t.y), (t.x + 1)] = ' ' then pushq(t.y, t.x+1);
			if map[(t.y), (t.x - 1)] = ' ' then pushq(t.y, t.x-1);
		end;
		dump;
	end;
end.

