# .bashrc

# User specific aliases and functions

alias rm='rm -f'
alias cp='cp -f'
alias mv='mv -f'

# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

# Go to another server
alias pi='ssh pi@192.168.137.17'
alias plat='ssh -p 3389 root@106.10.46.72'
alias swin='ssh -p 1398 2013311553@swin.skku.edu'
alias swui='ssh -p 1398 2013311553@swui.skku.edu'
alias swye='ssh -p 1398 2013311553@swye.skku.edu'
alias swji='ssh -p 1398 2013311553@swji.skku.edu'

alias go='cd /var/www/html'

alias vi="vim"
alias a.out="./a.out"
alias aout="./a.out"
alias cls="clear"
