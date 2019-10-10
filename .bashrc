# .bashrc

# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

# Uncomment the following line if you don't like systemctl's auto-paging feature:
# export SYSTEMD_PAGER=

# User specific aliases and functions
# Initialize root 
if [ -e /opt/soft/root/v6.10.08/bin/thisroot.sh ]; then
  source /opt/soft/root/v6.10.08/bin/thisroot.sh
fi

