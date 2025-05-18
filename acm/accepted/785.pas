program x785;
{
	@JUDGE_ID:  20044WC 785 PASCAL "Siliconism"
}
type
	coords = record
		x : Longint;
		y : longint;
	end;

	mark = record
		x : longint;
		y : longint;
		c : char;
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
	markers : array [1..1000] of mark;
	mkno : longint; {no of markers}
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
	if (y <= 0) or (x <= 0) then exit;
	if map[y, x] <> ' ' then exit;
	map[y,x] := markers[i].c;
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
	n := 10000;
		mkno := 0;

	for k := 1 to n do begin
		if (eof(input)) then break;
		for j := 0 to 80 do begin
			map[j] := '';
		end;
		mkno := 0;
		for j := 1 to 1000 do begin
			markers[j].x := 0;
			markers[j].y := 0;
			markers[j].c := #0;
		end;
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
		{ find marking chars }
		for j := 1 to maph do begin
			for i := 1 to length(map[j]) do begin
				if (map[j,i] <> ' ') and (map[j,i] <> 'X') then begin
					inc(mkno);
					markers[mkno].x := i;
					markers[mkno].y := j;
					markers[mkno].c := map[j,i];
				end;
				{if (pos('*', map[j]) > 0) then begin t.x := pos('*', map[j]); t.y := j; end;}
			end;
		end;
		
		for i := 1 to mkno do begin
			{ init }
			t.x := 0;
			t.y := 0;
			for j := 1 to 2400 do begin q[j] := t; end;
			qs := 0;
			qe := 0;
			{process}

			t.x := markers[i].x;
			t.y := markers[i].y;
			map[t.y, t.x] := ' ';
			pushq(t.y, t.x);
			while (qs <> qe) do begin
				t := popq;
				pushq(t.y+1, t.x);
				pushq(t.y-1, t.x);
				pushq(t.y, t.x+1);
				pushq(t.y, t.x-1);
			end;
		end;
		dump;
	end;
end.

