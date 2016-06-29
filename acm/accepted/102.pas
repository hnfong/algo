program p102;
{
	@JUDGE_ID:  20044WC 102 PASCAL

	Oh damnit....... This was easier than I had thought......
}
const
	p : array[1..6] of string[3] = ('BCG', 'BGC', 'CBG', 'CGB', 'GBC', 'GCB');
var
	i,j,k : longint;
	m : longint;
	mp : string[3];
	t : longint;
	a : array[1..3,'B'..'G'] of longint;
begin
	while not eof do begin
		for i := 1 to 3 do begin
			read(a[i,'B']);
			read(a[i,'G']);
			read(a[i,'C']);
		end;
		readln;
		
		m := -1;
		for i := 1 to 6 do begin {try all configs}
			t := 0;
			for j := 1 to 3 do begin {3 boxes}
				if p[i,j] <> 'B' then t := t + a[j, 'B'];
				if p[i,j] <> 'C' then t := t + a[j, 'C'];
				if p[i,j] <> 'G' then t := t + a[j, 'G'];
			end;
			if (m = -1) or ( t < m ) then begin
				m := t;
				mp := p[i];
			end;
		end;
		writeln(mp, ' ', m);
	end;
end.
