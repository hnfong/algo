program p10191;
{
	@JUDGE_ID: 20044WC 10191 PASCAL "DaP/DyP"

	STUPID ALGO
	I couldn't AC if i tried to use the more "usual" algo like sorting the times and trying to calc the max time by subtraction...
	NOW I FILL TIMELINE!!
}
type
	t = record
		h,m : longint;
	end;
var
	i,j,k : longint;
	w : array[0..101,1..2] of t;
	n : longint;
	s : string; { for reading stupid input }
	c : char; { input reader }
	a,b : longint;
	f : longint;
	bt : longint;
	ni : longint;
	tl : array[1..1200] of byte;
function zero(a:longint):string;
var
	s : string;
begin
	str(a,s);
	if a < 10 then zero := '0'+s else zero := s;
end;
begin
	ni := 0;
	while not eof do begin
		inc(ni);
		readln(n);
		for i := 1 to n do begin
			read(c);
			a := 10 * (ord(c)-48);
			read(c);
			a := a + ord(c)-48;
			read(c); { colon }
			read(c);
			b := 10 * (ord(c)-48);
			read(c);
			b := b + ord(c)-48;
			read(c); { space }
			w[i,1].h := a;
			w[i,1].m := b;
			 
			read(c);
			a := 10 * (ord(c)-48);
			read(c);
			a := a + ord(c)-48;
			read(c); { colon }
			read(c);
			b := 10 * (ord(c)-48);
			read(c);
			b := b + ord(c)-48;
			w[i,2].h := a;
			w[i,2].m := b;
			readln(s); { fsck crap }
		end;
		
		fillchar(tl,sizeof(tl),0);
		for i := 1 to n do begin
			for j := w[i,1].h*60+w[i,1].m to w[i,2].h*60+w[i,2].m-1 do begin
				tl[j] := 1;
			end;
		end;
		f := 0; bt := 0; k := 0; j := 10*60;
		for i := 10*60 to 18*60 do begin
			if k > f then begin
				bt := j;
				f := k;
			end;
			if tl[i] = 0 then inc(k) else begin
				k := 0;
				j := i+1;
			end;
		end;
		a := bt div 60;
		b := bt mod 60;
		write('Day #',ni,': the longest nap starts at ',a,':',zero(b),' and will last for ');
		a := f div 60;
		b := f mod 60;
		if a > 0 then write(a, ' hours and ');
		writeln(b, ' minutes.');
	end;
end.
