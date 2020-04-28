" Highlight invisibles
set list listchars=eol:¬,tab:>·,trail:.,extends:>,precedes:<,space:.

" Preceeding spaces DarkBlue, all other spaces black
highlight WhiteSpaceBol ctermfg=DarkBlue
highlight WhiteSpaceMol ctermfg=black
match WhiteSpaceMol / /
2match WhiteSpaceBol /^ \+/

" Soft tabs of length 2, and backspace knows about softtabs
:set tabstop=2
:set softtabstop=2
:set shiftwidth=2
:set expandtab

" Set indent on newline
set smartindent
