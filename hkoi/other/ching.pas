{

	This software is distributed under the GNU GPL licence.
	If you do not have the licence text, you can get one from
	http://www.gnu.org
	The author disclaims all possible problems arising from this program, and
	is not liable for any loss directly or indirectly caused
}

program chinglish;
var
        f : text;
        s : string;
        c : char;
        s2 : string;
        q : boolean;
	datching : array[1..10000] of string[20];
	datchin : array[1..10000] of string[20];
	n : longint;
	i : longint;
begin
	n := 0;
	assign(f,'chinglish.txt');
        reset(f);
	while not eof(f) do begin
		readln(f,s2);
		inc(n);
		datching[n] := copy(s2,1,pos('$', s2)-1);
		datchin[n] := (copy(s2,pos('$',s2)+1,pos('#',s2)-pos('$',s2)-1));
	end;
        close(f);
	
        s := '';
        while not eof do begin
                read(c);
                if ((c >= 'a') and (c <= 'z')) or ((c >= 'A') and (c <= 'Z')) then begin
                        s := s + c;
                end else begin
                        q := false;
			for i := 1 to n do begin
                                if datching[i] = s then begin
                                        write(datchin[i]);
					write(c);
                                        q := true;
                                        break;
                                end;
                        end;
                        if not q then write(s,c);
                        s := '';
                end;
        end;
end.

