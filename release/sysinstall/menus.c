/*
 * The new sysinstall program.
 *
 * This is probably the last program in the `sysinstall' line - the next
 * generation being essentially a complete rewrite.
 *
 * $Id: menus.c,v 1.41.2.14 1995/06/04 01:57:21 jkh Exp $
 *
 * Copyright (c) 1995
 *	Jordan Hubbard.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer,
 *    verbatim and that no modifications are made prior to this
 *    point in the file.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by Jordan Hubbard
 *	for the FreeBSD Project.
 * 4. The name of Jordan Hubbard or the FreeBSD project may not be used to
 *    endorse or promote products derived from this software without specific
 *    prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY JORDAN HUBBARD ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL JORDAN HUBBARD OR HIS PETS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, LIFE OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

#include "sysinstall.h"

/* All the system menus go here.
 *
 * Hardcoded things like version number strings will disappear from
 * these menus just as soon as I add the code for doing inline variable
 * expansion.
 */

/* The initial installation menu */
DMenu MenuInitial = {
    DMENU_NORMAL_TYPE,
    "Welcome to FreeBSD 2.0.5!",	/* title */
    "This is the main menu of the FreeBSD installation system.  Please\n\
select one of the options below by using the arrow keys or typing the\n\
first character of the option name you're interested in.  Invoke an\n\
option by pressing [ENTER].",		/* prompt */
    "Press F1 for usage instructions",				/* help line */
    "usage.hlp",						/* help file */
    { { "Usage", "Quick start - How to use this menu system.",	/* U */
	DMENU_DISPLAY_FILE,	"usage.hlp", 0, 0	},
      { "Doc", "More detailed documentation on FreeBSD.",	/* D */
	DMENU_SUBMENU,	&MenuDocumentation, 0, 0	},
      { "Language", "Set your preferred language.",		/* L */
	DMENU_SUBMENU,	&MenuOptionsLanguage, 0, 0	},
      { "Options", "Select various options for this utility.",	/* O */
	DMENU_SUBMENU,	&MenuOptions, 0, 0		},
      { "Proceed", "Go to the installation menu",		/* P */
	DMENU_SUBMENU,	&MenuInstall, 0, 0		},
      { "Quit", "Exit this menu (and the installation)",	/* Q */
	DMENU_CANCEL, NULL, 0, 0 },
      { NULL } },
};

/* The main documentation menu */
DMenu MenuDocumentation = {
    DMENU_NORMAL_TYPE,
    "Documentation for FreeBSD 2.0.5",	/* Title */
    "If you are at all unsure about the configuration of your hardware\n\
or are looking to build a system specifically for FreeBSD, read the\n\
Hardware guide!  New users should also read the Install document for\n\
a step-by-step tutorial on installing FreeBSD.  For general information,\n\
consult the README file.  If you are having other problems, you may find\n\
answers in the FAQ.",
    "Confused?  Press F1 for help.",
    "usage.hlp",			/* help file */
    { { "README", "Read this for a general description of FreeBSD",	/* R */
	DMENU_DISPLAY_FILE,	"README", 0, 0		},
      { "Hardware", "The FreeBSD survival guide for PC hardware.",	/* H */
	DMENU_DISPLAY_FILE,	"hardware.hlp", 0, 0	},
      { "Install", "A step-by-step guide to installing FreeBSD.",	/* I */
	DMENU_DISPLAY_FILE,	"install.hlp", 0, 0	},
      { "Copyright", "The FreeBSD Copyright notices.",   		/* C */
	DMENU_DISPLAY_FILE,	"COPYRIGHT", 0, 0	},
      { "Release", "The release notes for this version of FreeBSD.",	/* R */
	DMENU_DISPLAY_FILE,	"RELNOTES", 0, 0	},
      { "FAQ", "Frequently Asked Questions about FreeBSD.",		/* F */
	DMENU_DISPLAY_FILE,	"faq.hlp", 0, 0		},
      { "Exit", "Exit this menu (returning to previous)",		/* E */
	DMENU_CANCEL, NULL, 0, 0 },
      { NULL } },
};

/*
 * The language selection menu.
 */
DMenu MenuOptionsLanguage = {
    DMENU_NORMAL_TYPE | DMENU_SELECTION_RETURNS,
    "Natural language selection",	/* title */
    "Please specify the language you would like to use by default.\n\n\
While almost all of the system's documentation is still written\n\
in english (and may never be translated), there are a few guides\n\
and types of system documentation that may be written in your\n\
preferred language.  When such are found, they will be used instead\n\
of the english versions.  This feature is nonetheless considered\n\
to be in experimental status at this time.",		/* prompt */
    "Press F1 for more information",	/* help line */
    "language.hlp",			/* help file */
    { { "Danish", "Danish language and character set (ISO-8859-1)",	/* D */
	DMENU_CALL,	lang_set_Danish, 0, 0	},
      { "Dutch", "Dutch language and character set (ISO-8859-1)",	/* D */
	DMENU_CALL,	lang_set_Dutch, 0, 0	},
      { "English", "English language (system default)",			/* E */
	DMENU_CALL,	lang_set_English, 0, 0	},
      { "French", "French language and character set (ISO-8859-1)",	/* F */
	DMENU_CALL,	lang_set_French, 0, 0	},
      { "German", "German language and character set (ISO-8859-1)",	/* G */
	DMENU_CALL,	lang_set_German, 0, 0	},
      { "Italian", "Italian language and character set (ISO-8859-1)",	/* I */
	DMENU_CALL,	lang_set_Italian, 0, 0	},
      { "Japanese", "Japanese language and default character set (romaji)", /* J */
	DMENU_CALL,	lang_set_Japanese, 0, 0	},
      { "Norwegian", "Norwegian language and character set (ISO-8859-1)", /* N */
	DMENU_CALL,	lang_set_Norwegian, 0, 0},
      { "Russian", "Russian language and character set (KOI8-R)",	/* R */
	DMENU_CALL,	lang_set_Russian, 0, 0	},
      { "Spanish", "Spanish language and character set (ISO-8859-1)",	/* S */
	DMENU_CALL,	lang_set_Spanish, 0, 0	},
      { "Swedish", "Swedish language and character set (ISO-8859-1)",	/* S */
	DMENU_CALL,	lang_set_Swedish, 0, 0	},
      { NULL } },
};

DMenu MenuMediaCDROM = {
    DMENU_NORMAL_TYPE | DMENU_SELECTION_RETURNS,
    "Choose a CDROM type",
    "FreeBSD can be installed directly from a CDROM containing a valid\n\
FreeBSD 2.0.5 distribution.  If you are seeing this menu it is because\n\
more than one CDROM drive was found on your system.  Please select one\n\
of the following CDROM drives as your installation drive.",
    "Press F1 to read the installation guide",
    "install.hlp",
    { { NULL } },
};

DMenu MenuMediaFloppy = {
    DMENU_NORMAL_TYPE | DMENU_SELECTION_RETURNS,
    "Choose a Floppy drive",
"You have more than one floppy drive.  Please chose the drive\n\
you would like to use for this operation",
    NULL,
    NULL,
    { { NULL } },
};

DMenu MenuMediaDOS = {
    DMENU_NORMAL_TYPE | DMENU_SELECTION_RETURNS,
    "Choose a DOS partition",
"FreeBSD can be installed directly from a DOS partition\n\
assuming, of course, that you have copied the relevant\n\
distributions into your DOS partition before starting this\n\
installation.  If this is not the case then you should reboot\n\
DOS at this time and copy the distributions you wish to install\n\
into a \"FREEBSD\" subdirectory on one of your DOS partitions.\n\
Otherwise, please select the DOS partition containing the FreeBSD\n\
distribution files.",
    "Press F1 to read the installation guide",
    "install.hlp",
    { { NULL } },
};

DMenu MenuMediaFTP = {
    DMENU_NORMAL_TYPE | DMENU_SELECTION_RETURNS,
    "Please specify an FTP site",
    "FreeBSD is distributed from a number of sites on the Internet. Please\n\
select the site closest to you or \"other\" if you'd like to specify another\n\
choice.  Also note that not all sites carry every possible distribution!\n\
Distributions other than the basic user set are only guaranteed to be\n\
available from the Primary site.\n\n\
If the first site selected doesn't respond, try one of the alternates.\n\
You may also wish to investigate the options menu in case of trouble.\n\
To specify a URL not in this list, chose \"other\".",
    "Select a site that's close!",
    "install.hlp",
    { { "Primary Site",  "ftp.freebsd.org",
	DMENU_SET_VARIABLE,	"ftp=ftp://ftp.freebsd.org/pub/FreeBSD/2.0.5-ALPHA", 0, 0			},
      { "Secondary Site", "freefall.cdrom.com",
	DMENU_SET_VARIABLE,	"ftp=ftp://freefall.cdrom.com/pub/FreeBSD/2.0.5-ALPHA", 0, 0			},
      { "Other", "Specify some other ftp site by URL",
	DMENU_SET_VARIABLE,	"ftp=other", 0, 0								},
      { "Australia", "ftp.physics.usyd.edu.au",
	DMENU_SET_VARIABLE,	"ftp=ftp://ftp.physics.usyd.edu.au/FreeBSD/2.0.5-ALPHA", 0, 0			},
      { "Finland", "nic.funet.fi",
	DMENU_SET_VARIABLE,	"ftp=ftp://nic.funet.fi/pub/unix/FreeBSD/2.0.5-ALPHA", 0, 0			},
      { "France", "ftp.ibp.fr",
	DMENU_SET_VARIABLE,	"ftp=ftp://ftp.ibp.fr/pub/FreeBSD/2.0.5-ALPHA", 0, 0				},
      { "Germany", "ftp.fb9dv.uni-duisburg.de",
	DMENU_SET_VARIABLE,	"ftp=ftp://ftp.fb9dv.uni-duisburg.de/pub/unix/FreeBSD/2.0.5-ALPHA", 0, 0	},
      { "Germany #2", "gil.physik.rwth-aachen.de",
	DMENU_SET_VARIABLE,	"ftp=ftp://gil.physik.rwth-aachen.de/pub/FreeBSD/2.0.5-ALPHA", 0, 0		},
      { "Germany #3", "ftp.uni-paderborn.de",
	DMENU_SET_VARIABLE,	"ftp=ftp://ftp.uni-paderborn.de/freebsd/2.0.5-ALPHA", 0, 0			},
      { "Hong Kong", "ftp.hk.super.net",
	DMENU_SET_VARIABLE,	"ftp=ftp://ftp.hk.super.net/pub/FreeBSD/2.0.5-ALPHA", 0, 0			},
      { "Israel", "orgchem.weizmann.ac.il",
	DMENU_SET_VARIABLE,	"ftp=ftp://orgchem.weizmann.ac.il/pub/FreeBSD-2.0.5-ALPHA", 0, 0		},
      { "Japan", "ftp.sra.co.jp",
	DMENU_SET_VARIABLE,	"ftp=ftp://ftp.sra.co.jp/pub/os/FreeBSD/2.0.5-ALPHA", 0, 0			},
      { "Japan #2", "ftp.mei.co.jp",
	DMENU_SET_VARIABLE,	"ftp=ftp://ftp.mei.co.jp/free/PC-UNIX/FreeBSD/2.0.5-ALPHA", 0, 0		},
      { "Japan #3", "ftp.waseda.ac.jp",
	DMENU_SET_VARIABLE,	"ftp=ftp://ftp.waseda.ac.jp/pub/FreeBSD/2.0.5-ALPHA", 0, 0			},
      { "Japan #4", "ftp.pu-toyama.ac.jp",
	DMENU_SET_VARIABLE,	"ftp=ftp://ftp.pu-toyama.ac.jp/pub/FreeBSD/2.0.5-ALPHA", 0, 0			},
      { "Japan #5", "ftpsv1.u-aizu.ac.jp",
	DMENU_SET_VARIABLE,	"ftp=ftp://ftpsv1.u-aizu.ac.jp/pub/os/FreeBSD/2.0.5-ALPHA", 0, 0		},
      { "Japan #6", "ftp.tut.ac.jp",
	DMENU_SET_VARIABLE,	"ftp://ftp.tut.ac.jp/FreeBSD/2.0.5-ALPHA", 0, 0					},
      { "Japan #7", "ftp.ee.uec.ac.jp",
	DMENU_SET_VARIABLE,	"ftp=ftp://ftp.ee.uec.ac.jp/pub/os/mirror/ftp.freebsd.org/2.0.5-ALPHA", 0, 0	},
      { "Japan #8", "ftp.tokyonet.ad.jp",
	DMENU_SET_VARIABLE,	"ftp://ftp.tokyonet.ad.jp/pub/FreeBSD/2.0.5-ALPHA", 0, 0			},
      { "Korea", "ftp.cau.ac.kr",
	DMENU_SET_VARIABLE,	"ftp=ftp://ftp.cau.ac.kr/pub/FreeBSD/2.0.5-ALPHA", 0, 0				},
      { "Netherlands", "ftp.nl.net",
	DMENU_SET_VARIABLE,	"ftp=ftp://ftp.nl.net/pub/os/FreeBSD/2.0.5-ALPHA", 0, 0				},
      { "Russia", "ftp.kiae.su",
	DMENU_SET_VARIABLE,	"ftp=ftp://ftp.kiae.su/FreeBSD/2.0.5-ALPHA", 0, 0				},
      { "Sweden", "ftp.luth.se",
	DMENU_SET_VARIABLE,	"ftp=ftp://ftp.luth.se/pub/FreeBSD/2.0.5-ALPHA", 0, 0				},
      { "Taiwan", "netbsd.csie.nctu.edu.tw",
	DMENU_SET_VARIABLE,	"ftp=ftp://netbsd.csie.nctu.edu.tw/pub/FreeBSD/2.0.5-ALPHA", 0, 0		},
      { "Thailand", "ftp.nectec.or.th",
	DMENU_SET_VARIABLE,	"ftp=ftp://ftp.nectec.or.th/pub/FreeBSD/2.0.5-ALPHA", 0, 0			},
      { "UK", "ftp.demon.co.uk",
	DMENU_SET_VARIABLE,	"ftp=ftp://ftp.demon.co.uk/pub/BSD/FreeBSD/2.0.5-ALPHA", 0, 0			},
      { "UK #2", "src.doc.ic.ac.uk",
	DMENU_SET_VARIABLE,	"ftp=ftp://src.doc.ic.ac.uk/packages/unix/FreeBSD/2.0.5-ALPHA", 0, 0		},
      { "UK #3", "unix.hensa.ac.uk",
	DMENU_SET_VARIABLE,	"ftp=ftp://unix.hensa.ac.uk/mirrors/walnut.creek/FreeBSD/2.0.5-ALPHA", 0, 0		},
      { "USA", "ref.tfs.com",
	DMENU_SET_VARIABLE,	"ftp=ftp://ref.tfs.com/pub/FreeBSD/2.0.5-ALPHA", 0, 0				},
      { "USA #2", "ftp.dataplex.net",
	DMENU_SET_VARIABLE,	"ftp=ftp://ftp.dataplex.net/pub/FreeBSD/2.0.5-ALPHA", 0, 0			},
      { "USA #3", "kryten.atinc.com",
	DMENU_SET_VARIABLE,	"ftp=ftp://kryten.atinc.com/pub/FreeBSD/2.0.5-ALPHA", 0, 0			},
      { "USA #4", "ftp.neosoft.com",
	DMENU_SET_VARIABLE,	"ftp=ftp://ftp.neosoft.com/systems/FreeBSD/2.0.5-ALPHA", 0, 0			},
      { NULL } }
};

DMenu MenuMediaTape = {
    DMENU_NORMAL_TYPE | DMENU_SELECTION_RETURNS,
    "Choose a tape drive type",
    "FreeBSD can be installed from tape drive, though this installation\n\
method requires a certain amount of temporary storage in addition\n\
to the space required by the distribution itself (tape drives make\n\
poor random-access devices, so we extract _everything_ on the tape\n\
in one pass).  If you have sufficient space for this, then you should\n\
select one of the following tape devices detected on your system.",
    "Press F1 to read the installation guide",
    "install.hlp",
    { { NULL } },
};

DMenu MenuNetworkDevice = {
    DMENU_NORMAL_TYPE | DMENU_SELECTION_RETURNS,
    "Choose a network interface type",
"FreeBSD can be installed directly over a network, using NFS or FTP.\n
If you are using PPP over a serial device (cuaa0 or cuaa1) as opposed\n\
to a direct ethernet connection, then you may need to first dial your\n\
service provider using a special utility we provide for that purpose.\n\
You can also install over a parallel port using a special \"laplink\"\n\
cable, though this only works if you have another FreeBSD machine running\n\
a fairly recent (2.0R or later) release to talk to.\n\n\
To use PPP select one of the serial devices, otherwise select lp0 for\n\
the parallel port or one of the ethernet controllers (if you have one)\n\
for an ethernet installation.",
    "Press F1 to read network configuration manual",
    "network_device.hlp",
    { { NULL } },
};

/* The media selection menu */
DMenu MenuMedia = {
    DMENU_NORMAL_TYPE | DMENU_SELECTION_RETURNS,
    "Choose Installation Media",
    "FreeBSD can be installed from a variety of different installation\n\
media, ranging from floppies to the Internet.  If you're installing\n\
FreeBSD from a supported CDROM drive then this is generally the best\n\
method to use unless you have some overriding reason for using another\n\
method.",
    "Press F1 for more information on the various media types",
    "media.hlp",
    { { "CDROM", "Install from a FreeBSD CDROM",
	DMENU_CALL,	mediaSetCDROM, 0, 0		},
      { "DOS", "Install from a DOS partition",
	DMENU_CALL,	mediaSetDOS, 0, 0		},
      { "File System", "Install from a mounted filesystem",
	DMENU_CALL,	mediaSetUFS, 0, 0		},
      { "Floppy", "Install from a floppy disk set",
	DMENU_CALL,	mediaSetFloppy, 0, 0		},
      { "FTP", "Install from an Internet FTP server",
	DMENU_CALL,	mediaSetFTP, 0, 0		},
      { "NFS",		"Install over NFS",
	DMENU_CALL,	mediaSetNFS, 0, 0		},
      { "Tape", "Install from SCSI or QIC tape",
	DMENU_CALL,	mediaSetTape, 0, 0		},
      { NULL } },
};

/* The installation type menu */
DMenu MenuInstallType = {
    DMENU_NORMAL_TYPE | DMENU_SELECTION_RETURNS,
    "Choose Installation Type",
    "As a convenience, we provide several \"canned\" installation types.\n\
These select what we consider to be the most reasonable defaults for the\n\
type of system in question.  If you would prefer to pick and choose\n\
the list of distributions yourself, simply select \"custom\".",
    NULL,
    NULL,
    { { "Developer",	"Full sources, binaries and doc but no games [171MB]",
	DMENU_CALL,	distSetDeveloper, 0, 0		},
      { "X-Developer",	"Same as above, but includes XFree86 [196MB]",
	DMENU_CALL,	distSetXDeveloper, 0, 0		},
      { "Kern-Developer", "Full binaries and doc, kernel sources only [35MB]",
	DMENU_CALL,	distSetKernDeveloper, 0, 0	},
      { "User",		"Average user - binaries and doc but no sources [19MB]",
	DMENU_CALL,	distSetUser, 0, 0		},
      { "X-User",	"Same as above, but includes XFree86 [45MB]",
	DMENU_CALL,	distSetXUser, 0, 0		},
      { "Minimal",	"The smallest configuration possible [15MB]",
	DMENU_CALL,	distSetMinimum, 0, 0		},
      { "Everything",	"All sources, binaries and XFree86 binaries [203MB]",
	DMENU_CALL,	distSetEverything, 0, 0		},
      { "Custom",	"Specify your own distribution set [?]",
	DMENU_SUBMENU,	&MenuDistributions, 0, 0	},
      { "Reset",	"Reset selected distribution list to None",
	DMENU_CALL,	distReset, 0, 0			},
      { NULL } },
};

static char *
srcFlagCheck(DMenuItem *item)
{
    return (Dists & DIST_SRC) ? "YES" : "NO";
}

static char *
x11FlagCheck(DMenuItem *item)
{
    return (Dists & DIST_XF86) ? "YES" : "NO";
}

DMenu MenuDistributions = {
    DMENU_MULTIPLE_TYPE | DMENU_SELECTION_RETURNS,
    "Select the distributions you wish to install.",
    "Please check off the distributions you wish to install.  Some\n
of the most generally useful distributions are already checked, and\n\
selecting OK at this stage will chose them as defaults.\n\
WARNING:  Do not export the DES distribution out of the U.S.!",
    NULL,
    NULL,
    { { "bin", "Binary base distribution (required) [36MB]",
	DMENU_SET_FLAG,	&Dists, DIST_BIN, 0, dmenuFlagCheck	},
      { "commercial", "Commercial demos and shareware [10MB]",
	DMENU_SET_FLAG,	&Dists, DIST_COMMERCIAL, 0, dmenuFlagCheck	},
      { "compat1x", "FreeBSD 1.x binary compatability package [2MB]",
	DMENU_SET_FLAG,	&Dists, DIST_COMPAT1X, 0, dmenuFlagCheck	},
      { "compat20", "FreeBSD 2.0 binary compatability package [2MB]",
	DMENU_SET_FLAG,	&Dists, DIST_COMPAT20, 0, dmenuFlagCheck	},
      { "DES", "DES encryption code and sources [.3MB]",
	DMENU_SET_FLAG,	&Dists, DIST_DES, 0, dmenuFlagCheck		},
      { "dict", "Spelling checker dictionary files [4.2MB]",
	DMENU_SET_FLAG,	&Dists, DIST_DICT, 0, dmenuFlagCheck		},
      { "games", "Games and other amusements (non-commercial) [6.4MB]",
	DMENU_SET_FLAG,	&Dists, DIST_GAMES, 0, dmenuFlagCheck		},
      { "info", "GNU info files [4.1MB]",
	DMENU_SET_FLAG,	&Dists, DIST_INFO, 0, dmenuFlagCheck		},
      { "man", "System manual pages - strongly recommended [3.3MB]",
	DMENU_SET_FLAG,	&Dists, DIST_MANPAGES, 0, dmenuFlagCheck	},
      { "proflibs", "Profiled versions of the libraries [3.3MB]",
	DMENU_SET_FLAG,	&Dists, DIST_PROFLIBS, 0, dmenuFlagCheck	},
      { "src", "Sources for everything but DES [120MB]",
	DMENU_CALL,	distSetSrc, 0, 0, srcFlagCheck			},
      { "XFree86", "The XFree86 3.1.1L distribution [?]",
	DMENU_CALL,	distSetXF86, 0, 0, x11FlagCheck			},
      { NULL } },
};

DMenu MenuSrcDistributions = {
    DMENU_MULTIPLE_TYPE | DMENU_SELECTION_RETURNS,
    "Select the sub-components of src you wish to install.",
    "Please check off those portions of the FreeBSD source tree\n\
you wish to install.",
    NULL,
    NULL,
    { { "base", "top-level files in /usr/src [300K]",
	DMENU_SET_FLAG,	&SrcDists, DIST_SRC_BASE, 0, dmenuFlagCheck	},
      { "gnu", "/usr/src/gnu (software from the GNU Project) [42MB]]",
	DMENU_SET_FLAG,	&SrcDists, DIST_SRC_GNU, 0, dmenuFlagCheck	},
      { "etc", "/usr/src/etc (miscellaneous system files) [460K]",
	DMENU_SET_FLAG,	&SrcDists, DIST_SRC_ETC, 0, dmenuFlagCheck	},
      { "games", "/usr/src/games (diversions) [7.8MB]",
	DMENU_SET_FLAG,	&SrcDists, DIST_SRC_GAMES, 0, dmenuFlagCheck	},
      { "include", "/usr/src/include (header files) [467K]",
	DMENU_SET_FLAG,	&SrcDists, DIST_SRC_INCLUDE, 0, dmenuFlagCheck	},
      { "lib", "/usr/src/lib (system libraries) [9.2MB]",
	DMENU_SET_FLAG,	&SrcDists, DIST_SRC_LIB, 0, dmenuFlagCheck	},
      { "libexec", "/usr/src/libexec (system programs) [1.2MB]",
	DMENU_SET_FLAG,	&SrcDists, DIST_SRC_LIBEXEC, 0, dmenuFlagCheck	},
      { "lkm", "/usr/src/lkm (Loadable Kernel Modules) [193K]",
	DMENU_SET_FLAG,	&SrcDists, DIST_SRC_LKM, 0, dmenuFlagCheck	},
      { "release", "/usr/src/release (release-generation tools) [533K]",
	DMENU_SET_FLAG,	&SrcDists, DIST_SRC_RELEASE, 0, dmenuFlagCheck	},
      { "sbin", "/usr/src/sbin (system binaries) [1.3MB]",
	DMENU_SET_FLAG,	&SrcDists, DIST_SRC_SBIN, 0, dmenuFlagCheck	},
      { "share", "/usr/src/share (documents and shared files) [10MB]",
	DMENU_SET_FLAG,	&SrcDists, DIST_SRC_SHARE, 0, dmenuFlagCheck	},
      { "sys", "/usr/src/sys (FreeBSD kernel) [13MB]",
	DMENU_SET_FLAG,	&SrcDists, DIST_SRC_SYS, 0, dmenuFlagCheck	},
      { "ubin", "/usr/src/usr.bin (user binaries) [13MB]",
	DMENU_SET_FLAG,	&SrcDists, DIST_SRC_UBIN, 0, dmenuFlagCheck	},
      { "usbin", "/usr/src/usr.sbin (aux system binaries) [14MB]",
	DMENU_SET_FLAG,	&SrcDists, DIST_SRC_USBIN, 0, dmenuFlagCheck	},
      { NULL } },
};

static int
clearx11(char *str)
{
    XF86Dists = 0;
    XF86ServerDists = 0;
    XF86FontDists = 0;
    Dists &= ~DIST_XF86;
    return 1;
}

DMenu MenuXF86Select = {
    DMENU_NORMAL_TYPE,
    "XFree86 3.1.1u1 Distribution",
    "Please select the components you need from the XFree86 3.1.1u1\n\
distribution.  We recommend that you select what you need from the basic\n\
components set and at least one entry from the Server and Font set menus.",
    "Press F1 to read the XFree86 release notes for FreeBSD",
    "XF86.hlp",
    { { "Basic", "Basic component menu (required)",			/* B */
	DMENU_SUBMENU, &MenuXF86SelectCore, 0, 0	},
      { "Server", "X server menu",					/* S */
	DMENU_SUBMENU, &MenuXF86SelectServer, 0, 0	},
      { "Fonts", "Font set menu",					/* F */
	DMENU_SUBMENU, &MenuXF86SelectFonts, 0, 0	},
      { "Clear", "Reset XFree86 distribution list",
	DMENU_CALL, clearx11, 0, 0, 0			},
      { "Exit", "Exit this menu (returning to previous)",		/* E */
	DMENU_CANCEL, NULL, 0, 0 },
      { NULL } },
};

DMenu MenuXF86SelectCore = {
    DMENU_MULTIPLE_TYPE | DMENU_SELECTION_RETURNS,
    "XFree86 3.1.1 base distribution types",
    "Please check off the basic XFree86 components you wish to install.",
    "Press F1 to read the XFree86 release notes for FreeBSD",
    "XF86.hlp",
    { { "bin", "X client applications and shared libs [4MB].",
	DMENU_SET_FLAG,	&XF86Dists, DIST_XF86_BIN, 0, dmenuFlagCheck	},
      { "lib", "Data files needed at runtime [600K]",
	DMENU_SET_FLAG,	&XF86Dists, DIST_XF86_LIB, 0, dmenuFlagCheck	},
      { "xicf", "Customizable xinit runtime configuration file [100K]",
	DMENU_SET_FLAG,	&XF86Dists, DIST_XF86_XINIT, 0, dmenuFlagCheck	},
      { "xdcf", "Customizable xdm runtime configuration file [100K]",
	DMENU_SET_FLAG,	&XF86Dists, DIST_XF86_XDMCF, 0, dmenuFlagCheck	},
      { "doc", "READMEs and XFree86 specific man pages [500K]",
	DMENU_SET_FLAG,	&XF86Dists, DIST_XF86_DOC, 0, dmenuFlagCheck	},
      { "man", "Man pages (except XFree86 specific ones) [1.2MB]",
	DMENU_SET_FLAG,	&XF86Dists, DIST_XF86_MAN, 0, dmenuFlagCheck	},
      { "prog", "Programmer's header and library files [4MB]",
	DMENU_SET_FLAG,	&XF86Dists, DIST_XF86_PROG, 0, dmenuFlagCheck	},
      { "link", "X Server reconfiguration kit [7.8MB]",
	DMENU_SET_FLAG,	&XF86Dists, DIST_XF86_LINK, 0, dmenuFlagCheck	},
      { "pex", "PEX fonts and libs needed by PEX apps [500K]",
	DMENU_SET_FLAG,	&XF86Dists, DIST_XF86_PEX, 0, dmenuFlagCheck	},
      { "sources", "XFree86 3.1.1u1 source + contrib distribution [200MB]",
	DMENU_SET_FLAG,	&XF86Dists, DIST_XF86_SRC, 0, dmenuFlagCheck	},
      { NULL } },
};

DMenu MenuXF86SelectFonts = {
    DMENU_MULTIPLE_TYPE | DMENU_SELECTION_RETURNS,
    "Font distribution selection.",
    "Please check off the individual font distributions you wish to\n\
install.  At the minimum, you should install the standard\n\
75 DPI and misc fonts if you're also installing a server\n\
(these are selected by default).",
    "Press F1 to read the XFree86 release notes for FreeBSD",
    "XF86.hlp",
    { { "fnts", "Standard 75 DPI and miscellaneous fonts [3.6MB]",
	DMENU_SET_FLAG,	&XF86FontDists, DIST_XF86_FONTS_MISC, 0, dmenuFlagCheck		},
      { "f100", "100 DPI fonts [1.8MB]",
	DMENU_SET_FLAG,	&XF86FontDists, DIST_XF86_FONTS_100, 0, dmenuFlagCheck		},
      { "fscl", "Speedo and Type scalable fonts [1.6MB]",
	DMENU_SET_FLAG,	&XF86FontDists, DIST_XF86_FONTS_SCALE, 0, dmenuFlagCheck	},
      { "non", "Japanese, Chinese and other non-english fonts [3.3MB]",
	DMENU_SET_FLAG,	&XF86FontDists, DIST_XF86_FONTS_NON, 0, dmenuFlagCheck		},
      { "server", "Font server [0.3MB]",
	DMENU_SET_FLAG,	&XF86FontDists, DIST_XF86_FONTS_SERVER, 0, dmenuFlagCheck	},
      { NULL } },
};

DMenu MenuXF86SelectServer = {
    DMENU_MULTIPLE_TYPE | DMENU_SELECTION_RETURNS,
    "X Server selection.",
    "Please check off the types of X servers you wish to install.\n\
If you are unsure as to which server will work for your graphics card,\n\
it is recommended that try the SVGA or VGA16 servers (the VGA16 and\n\
Mono servers are particularly well-suited to most LCD displays).",
    "Press F1 to read the XFree86 release notes for FreeBSD",
    "XF86.hlp",
    { { "SVGA", "Standard VGA or Super VGA display [1MB]",
	DMENU_SET_FLAG,	&XF86ServerDists, DIST_XF86_SERVER_SVGA, 0, dmenuFlagCheck	},
      { "VGA16", "Standard 16 color VGA display [1MB]",
	DMENU_SET_FLAG,	&XF86ServerDists, DIST_XF86_SERVER_VGA16, 0, dmenuFlagCheck	},
      { "Mono", "Standard Monochrome display [1MB]",
	DMENU_SET_FLAG,	&XF86ServerDists, DIST_XF86_SERVER_MONO, 0, dmenuFlagCheck	},
      { "8514", "8-bit (256 color) IBM 8514 or compatible card [1MB]",
	DMENU_SET_FLAG,	&XF86ServerDists, DIST_XF86_SERVER_8514, 0, dmenuFlagCheck	},
      { "AGX", "8-bit AGX card [1MB]",
	DMENU_SET_FLAG,	&XF86ServerDists, DIST_XF86_SERVER_AGX, 0, dmenuFlagCheck	},
      { "Mch3", "8 and 16-bit (65K color) for ATI Mach32 card [1MB]",
	DMENU_SET_FLAG,	&XF86ServerDists, DIST_XF86_SERVER_MACH32, 0, dmenuFlagCheck	},
      { "Mch8", "8-bit ATI Mach8 card [1MB]",
	DMENU_SET_FLAG,	&XF86ServerDists, DIST_XF86_SERVER_MACH8, 0, dmenuFlagCheck	},
      { "P9K", "8, 16, and 24-bit color for Weitek P9000 based boards [1MB]",
	DMENU_SET_FLAG,	&XF86ServerDists, DIST_XF86_SERVER_P9000, 0, dmenuFlagCheck	},
      { "S3", "8, 16 and 24-bit color for S3 based boards [1MB]",
	DMENU_SET_FLAG,	&XF86ServerDists, DIST_XF86_SERVER_S3, 0, dmenuFlagCheck	},
      { "W32", "8-bit Color for ET4000/W32, /W32i and /W32p cards [1MB]",
	DMENU_SET_FLAG,	&XF86ServerDists, DIST_XF86_SERVER_W32, 0, dmenuFlagCheck	},
      { "nest", "A nested server for testing purposes [1MB]",
	DMENU_SET_FLAG,	&XF86ServerDists, DIST_XF86_SERVER_NEST, 0, dmenuFlagCheck	},
      { NULL } },
};

DMenu MenuDiskDevices = {
    DMENU_MULTIPLE_TYPE | DMENU_SELECTION_RETURNS,
    "Select Drive(s)",
    "Please select the drive, or drives, on which you wish to install\n\
FreeBSD.  You need to select at least one drive containing some free\n\
space, though FreeBSD can be installed across several drives if you do\n\
not have the required space on a single drive.  If you wish to boot\n\
off a drive that's not a `zero drive', or have multiple operating\n\
systems on your machine, you will have the option to install a boot\n\
manager later.  To select a drive, use the arrow keys to move to it\n\
and press [SPACE].",
    "Press F1 for important information regarding geometry!",
    "drives.hlp",
    { { NULL } },
};

/* Local work func for MenuOptions */
static int
clearFlags(char *str)
{
    OptFlags = 0;
    return 1;  /* Gross, but forces menu rebuild */
}

static char *
ftpFlagCheck(DMenuItem *item)
{
    /* Verify that everything's sane */
    if ((OptFlags & (OPT_FTP_ABORT + OPT_FTP_RESELECT)) == (OPT_FTP_ABORT + OPT_FTP_RESELECT))
	OptFlags &= ~OPT_FTP_RESELECT;
    if (!(OptFlags & (OPT_FTP_ABORT + OPT_FTP_RESELECT)))
	OptFlags |= OPT_FTP_ABORT;
    if ((OptFlags & (OPT_FTP_ACTIVE + OPT_FTP_PASSIVE)) == (OPT_FTP_ACTIVE + OPT_FTP_PASSIVE))
	OptFlags &= ~OPT_FTP_ACTIVE;
    if (!(OptFlags & (OPT_FTP_ACTIVE + OPT_FTP_PASSIVE)))
	OptFlags |= OPT_FTP_PASSIVE;
    if (*((unsigned int *)item->ptr) & item->parm)
        return "ON";
    return "OFF";
}

/* The installation options menu */
DMenu MenuOptions = {
    DMENU_MULTIPLE_TYPE | DMENU_SELECTION_RETURNS,
    "Choose Installation Options",
    "The following options control how this utility will deal\n\
with various possible error conditions and how verbose it will\n\
be at various stages.",
    "Press F1 for more help on these options",
    "options.hlp",
    { { "NFS Secure", "NFS server talks only on a secure port",
	DMENU_SET_FLAG,		&OptFlags, OPT_NFS_SECURE, 0, dmenuFlagCheck	},
      { "NFS Slow", "User is using a slow PC or ethernet card",
	DMENU_SET_FLAG,		&OptFlags, OPT_SLOW_ETHER, 0, dmenuFlagCheck		},
      { "FTP Abort", "On transfer failure, abort",
	DMENU_SET_FLAG,		&OptFlags, OPT_FTP_ABORT, 0, ftpFlagCheck	},
      { "FTP Reselect", "On transfer failure, ask for another host",
	DMENU_SET_FLAG,		&OptFlags, OPT_FTP_RESELECT, 0, ftpFlagCheck	},
      { "FTP active", "Use \"active mode\" for standard FTP",
	DMENU_SET_FLAG,		&OptFlags, OPT_FTP_ACTIVE, 0, ftpFlagCheck	},
      { "FTP passive", "Use \"passive mode\" for firewalled FTP",
	DMENU_SET_FLAG,		&OptFlags, OPT_FTP_PASSIVE, 0, ftpFlagCheck	},
      { "Extra Debugging", "Toggle the extra debugging flag",
	DMENU_SET_FLAG,		&OptFlags, OPT_DEBUG, 0, dmenuFlagCheck	},
      { "Yes To All", "Assume \"Yes\" answers to all non-critical dialogs",
	DMENU_SET_FLAG,	&OptFlags, OPT_NO_CONFIRM, 0, dmenuFlagCheck	},
      { "FTP userpass", "Specify username and password instead of anonymous",
	DMENU_CALL, mediaSetFtpUserPass, 0, 0			},
      { "Clear", "Clear All Option Flags",
	DMENU_CALL,		clearFlags, 0, 0 },
      { "Exit", "Exit this menu (returning to previous)",
	DMENU_CANCEL, NULL, 0, 0 },
      { NULL } },
};

/* The main installation menu */
DMenu MenuInstall = {
    DMENU_NORMAL_TYPE,
    "Choose Installation Options",		/* title */
    "Before installation can continue, you need to specify a few\n\
details on the type of distribution you wish to have, where you wish\n\
to install it from and how you wish to allocate disk storage to FreeBSD.\n\n\
None of the items in this menu will actually modify the contents of\n\
your disk until you select the \"Install\" menu item (and even then, only\n\
after a final confirmation).",
    "Press F1 to read the installation guide",
    "install.hlp",
    { { "Partition", "Allocate disk space for FreeBSD",		/* P */
	DMENU_CALL,	diskPartitionEditor, 0, 0	},
      { "Label", "Label allocated disk partitions",		/* L */
	DMENU_CALL,	diskLabelEditor, 0, 0		},
      { "Distributions", "Choose the type of installation you want", /* T */
	DMENU_SUBMENU,	&MenuInstallType, 0, 0		},
      { "Media", "Choose the installation media type",		/* M */
	DMENU_SUBMENU,	&MenuMedia, 0, 0		},
      { "Options", "Go to Options submenu",                        /* O */
	DMENU_SUBMENU, &MenuOptions, 0, 0		},
      { "Commit", "Install FreeBSD onto your hard disk(s)",	/* C */
	DMENU_CALL,	installCommit, 0, 0		},
      { "Configure", "Do post-install configuration of FreeBSD", /* C */
	DMENU_SUBMENU,	&MenuConfigure, 0, 0		},
      { "Exit", "Exit this menu (returning to previous)",
	DMENU_CANCEL, NULL, 0, 0 },
      { NULL } },
};

/* MBR type menu */
DMenu MenuMBRType = {
    DMENU_RADIO_TYPE | DMENU_SELECTION_RETURNS,
    "Chose boot manager type",		/* title */
    "FreeBSD comes with a boot selector that allows you to easily\n\
select between FreeBSD and other operating systems on your machine\n\
at boot time.  If you have more than one drive and wish to boot\n\
from other than the first, the boot selector will also allow you\n\
to do so (limitations in the PC BIOS usually prevent this otherwise).\n\
If you do not want a boot selector, or wish to replace an existing\n\
one, select \"standard\".  If you would prefer your Master Boot\n\
Record to remain untouched, then select \"none\".",
    "Press F1 to read the installation guide",
    "install.hlp",
    { { "BootMgr", "Install the FreeBSD Boot Manager (\"Booteasy\")", /* B */
	DMENU_SET_VALUE,	&BootMgr, 0, 0, dmenuRadioCheck	},
      { "Standard", "Use a standard MBR (no boot manager)",	/* S */
	DMENU_SET_VALUE,	&BootMgr, 1, 0, dmenuRadioCheck		},
      { "None", "Leave the Master Boot Record untouched",	/* N */
	DMENU_SET_VALUE,	&BootMgr, 2, 0, dmenuRadioCheck	},
      { NULL } },
};

/* Final configuration menu */
DMenu MenuConfigure = {
    DMENU_NORMAL_TYPE,
    "FreeBSD Configuration Menu",	/* title */
    "If you've already installed FreeBSD, you may use this menu to\n\
customize it somewhat to suit your particular configuration.  Most\n\
importantly, you can use the Packages utility to load extra \"3rd party\"\n\
software not provided in the base distributions.",
    "Press F1 for more information on these options",
    "configure.hlp",
    { { "Add User",	"Add users to the system",
	DMENU_SYSTEM_COMMAND, "adduser -silent", 0, 0		},
      { "Console",	"Customize system console behavior",
	DMENU_SUBMENU, &MenuSyscons, 0, 0			},
      { "Networking",	"Configure additional network services",
	DMENU_SUBMENU, 	&MenuNetworking, 0, 0			},
      { "Time Zone",	"Set which time zone you're in",
	DMENU_SYSTEM_COMMAND, "tzsetup", 0, 0			},
      { "Packages",	"Install extra FreeBSD packaged software",
	DMENU_CALL,	configPackages, 0, 0			},
      { "Ports",	"Enable the FreeBSD Ports Collection from CD",
	DMENU_CALL,	configPorts, 0, 1			},
      { "Root Password", "Set the system manager's password",
	DMENU_SYSTEM_COMMAND, "passwd root", 0, 0		},
      { "XFree86",	"Configure XFree86 (if installed)",
	DMENU_SYSTEM_COMMAND, "PATH=/usr/bin:/bin:/usr/X11R6/bin xf86config", 0, 0 },
      { "Exit", "Exit this menu (returning to previous)",
	DMENU_CANCEL, NULL, 0, 0 },
      { NULL } },
};

DMenu MenuNetworking = {
    DMENU_NORMAL_TYPE,
    "Network Services Menu",
    "You may have already configured one network device (and the\n\
other various hostname/gateway/name server parameters) in the process\n\
of installing FreeBSD.  This menu allows you to configure other\n\
aspects of your system's network configuration.",
    NULL,
    NULL,
    { { "NFS client",	"This machine will be an NFS client",
	DMENU_SET_VARIABLE, "nfs_client=YES", 0, 0		},
      { "NFS server",	"This machine will be an NFS server",
	DMENU_SET_VARIABLE, "nfs_server=YES", 0, 0		},
      { "Interfaces",	"Configure network interfaces",
	DMENU_CALL,	tcpMenuSelect, 0, 0			},
      { "ntpdate",	"Select a clock-syncronization server",
	DMENU_SUBMENU,	&MenuNTP, 0, 0				},
      { "routed",	"Set flags for routed (default: -q)",
	DMENU_CALL,	configRoutedFlags, 0, 0			},
      { "rwhod",	"This machine wants to run the rwho daemon",
	DMENU_SET_VARIABLE, "rwhod=YES", 0, 0			},
      { "Exit", "Exit this menu (returning to previous)",
	DMENU_CANCEL, NULL, 0, 0 },
      { NULL } },
};

DMenu MenuNTP = {
    DMENU_NORMAL_TYPE | DMENU_SELECTION_RETURNS,
    "NTPDATE Server Selection",
    "There are a number of time syncronization servers available\n\
for public use around the Internet.  Please select one reasonably\n\
close to you to have your system time syncronized accordingly.",
    "These are the primary open-access NTP servers",
    NULL,
    { { "Australia",		"ntp.syd.dms.csiro.au (HP 5061 Cesium Beam)",
	DMENU_SET_VARIABLE,	"ntpdate=ntp.syd.dms.csiro.au", 0, 0	},
      { "Canada",		"tick.usask.ca (GOES clock)",
	DMENU_SET_VARIABLE,	"ntpdate=tick.usask.ca", 0, 0		},
      { "France",		"canon.inria.fr (TDF clock)",
	DMENU_SET_VARIABLE,	"ntpdate=canon.inria.fr", 0, 0		},
      { "Germany",		"ntps1-{0,1,2}.uni-erlangen.de (GPS)",
	DMENU_SET_VARIABLE,	"ntpdate=ntps1-0.uni-erlangen.de", 0, 0	},
      { "Germany #2",		"ntps1-0.cs.tu-berlin.de (GPS)",
	DMENU_SET_VARIABLE,	"ntpdate=ntps1-0.cs.tu-berlin.de", 0, 0	},
      { "Japan",		"clock.nc.fukuoka-u.ac.jp (GPS clock)",
	DMENU_SET_VARIABLE,	"ntpdate=clock.nc.fukuoka-u.ac.jp", 0, 0},
      { "Japan #2",		"clock.tl.fukuoka-u.ac.jp (GPS clock)",
	DMENU_SET_VARIABLE,	"ntpdate=clock.tl.fukuoka-u.ac.jp", 0, 0},
      { "Netherlands",		"ntp0.nl.net (GPS clock)",
	DMENU_SET_VARIABLE,	"ntpdate=ntp0.nl.net", 0, 0		},
      { "Norway",		"timer.unik.no (NTP clock)",
	DMENU_SET_VARIABLE,	"ntpdate=timer.unik.no", 0, 0		},
      { "Sweden",		"Time1.Stupi.SE (Cesium/GPS)",
	DMENU_SET_VARIABLE,	"ntpdate=Time1.Stupi.SE", 0, 0		},
      { "Switzerland",		"swisstime.ethz.ch (DCF77 clock)",
	DMENU_SET_VARIABLE,	"ntpdate=swisstime.ethz.ch", 0, 0	},
      { "U.S. East Coast",	"bitsy.mit.edu (WWV clock)",
	DMENU_SET_VARIABLE,	"ntpdate=bitsy.mit.edu", 0, 0		},
      { "U.S. East Coast #2",	"otc1.psu.edu (WWV clock)",
	DMENU_SET_VARIABLE,	"ntpdate=otc1.psu.edu", 0, 0		},
      { "U.S. West Coast",	"apple.com (WWV clock)",
	DMENU_SET_VARIABLE,	"ntpdate=apple.com", 0, 0		},
      { "U.S. West Coast #2",	"clepsydra.dec.com (GOES clock)",
	DMENU_SET_VARIABLE,	"ntpdate=clepsydra.dec.com", 0, 0	},
      { "U.S. West Coast #3",	"clock.llnl.gov (WWVB clock)",
	DMENU_SET_VARIABLE,	"ntpdate=clock.llnl.gov", 0, 0		},
      { "U.S. Midwest",		"ncar.ucar.edu (WWVB clock)",
	DMENU_SET_VARIABLE,	"ntpdate=ncar.ucar.edu", 0, 0		},
      { "U.S. Pacific",		"chantry.hawaii.net (WWV/H clock)",
	DMENU_SET_VARIABLE,	"ntpdate=chantry.hawaii.net", 0, 0	},
      { "U.S. Southwest",	"shorty.chpc.utexas.edu (WWV clock)",
	DMENU_SET_VARIABLE,	"ntpdate=shorty.chpc.utexas.edu", 0, 0	},
      { NULL } },
};

DMenu MenuSyscons = {
    DMENU_NORMAL_TYPE,
    "System Console Configuration",
    "The default system console driver for FreeBSD (syscons) has a\n\
number of configuration options which may be set according to\n\
your preference.\n\n\
When you are done setting configuration options, select Cancel.",
    "Configure your system console settings",
    NULL,
    { { "Keymap", "Choose an alternate keyboard map",
	DMENU_SUBMENU, &MenuSysconsKeymap, 0, 0		},
      { "Repeat", "Set the rate at which keys repeat",
	DMENU_SUBMENU, &MenuSysconsKeyrate, 0, 0	},
      { "Saver", "Configure the screen saver",
	DMENU_SUBMENU, &MenuSysconsSaver, 0, 0		},
      { "Exit", "Exit this menu (returning to previous)",
	DMENU_CANCEL, NULL, 0, 0 },
      { NULL } },
};

DMenu MenuSysconsKeymap = {
    DMENU_NORMAL_TYPE | DMENU_SELECTION_RETURNS,
    "System Console Keymap",
    "The default system console driver for FreeBSD (syscons) defaults\n\
to a standard \"American\" keyboard map.  Users in other countries\n\
(or with different keyboard preferences) may wish to choose one of\n\
the other keymaps below.",
    "Choose a keyboard map",
    NULL,
    { { "Danish CP865", "Danish Code Page 865 keymap",
	DMENU_SET_VARIABLE, "keymap=danish.cp865", 0, 0		},
      { "Danish ISO", "Danish ISO keymap",
	DMENU_SET_VARIABLE, "keymap=danish.iso", 0, 0		},
      { "French ISO", "French ISO keymap",
	DMENU_SET_VARIABLE, "keymap=fr.iso", 0, 0		},
      { "German CP850", "German Code Page 850 keymap",
	DMENU_SET_VARIABLE, "keymap=german.cp850", 0, 0		},
      { "German ISO", "German ISO keymap",
	DMENU_SET_VARIABLE, "keymap=german.iso", 0, 0		},
      { "Russian CP866", "Russian Code Page 866 keymap",
	DMENU_SET_VARIABLE, "keymap=ru.cp866", 0, 0		},
      { "Russian KOI8", "Russian koi8 keymap",
	DMENU_SET_VARIABLE, "keymap=ru.koi8-r", 0, 0		},
      { "Russian s-KOI8", "Russian shifted koi8 keymap",
	DMENU_SET_VARIABLE, "keymap=ru.koi8-r.shift", 0, 0	},
      { "Swedish CP850", "Swedish Code Page 850 keymap",
	DMENU_SET_VARIABLE, "keymap=swedish.cp850", 0, 0	},
      { "Swedish ISO", "Swedish ISO keymap",
	DMENU_SET_VARIABLE, "keymap=swedish.iso", 0, 0		},
      { "U.K. CP850", "United Kingdom Code Page 850 keymap",
	DMENU_SET_VARIABLE, "keymap=uk.cp850.iso", 0, 0		},
      { "U.K. ISO", "United Kingdom ISO keymap",
	DMENU_SET_VARIABLE, "keymap=uk.iso", 0, 0		},
      { "U.S. ISO", "United States ISO keymap",
	DMENU_SET_VARIABLE, "keymap=us.iso", 0, 0		},
      { NULL } },
};

DMenu MenuSysconsKeyrate = {
    DMENU_NORMAL_TYPE | DMENU_SELECTION_RETURNS,
    "System Console Keyboard Repeat Rate",
    "This menu allows you to set the speed at which keys repeat\n\
when held down.",
    "Choose a keyboard repeat rate",
    NULL,
    { { "Slow", "Slow keyboard repeat rate",
	DMENU_SET_VARIABLE, "keyrate=slow", 0, 0		},
      { "Normal", "\"Normal\" keyboard repeat rate",
	DMENU_SET_VARIABLE, "keyrate=normal", 0, 0		},
      { "Fast", "Fast keyboard repeat rate",
	DMENU_SET_VARIABLE, "keyrate=fast", 0, 0		},
      { "Default", "Use default keyboard repeat rate",
	DMENU_SET_VARIABLE, "keyrate=NO", 0, 0			},
      { NULL } },
};

DMenu MenuSysconsSaver = {
    DMENU_NORMAL_TYPE,
    "System Console Screen Saver",
    "By default, the console driver will not attempt to do anything\n\
special with your screen when it's idle.  If you expect to leave your\n\
monitor switched on and idle for long periods of time then you should\n\
probably enable one of these screen savers to prevent phosphor burn-in.",
    "Choose a nifty-looking screen saver",
    NULL,
    { { "blank", "Simply blank the screen",
	DMENU_SET_VARIABLE, "saver=star", 0, 0		},
      { "Green", "\"Green\" power saving mode (if supported by monitor)",
	DMENU_SET_VARIABLE, "saver=snake", 0, 0		},
      { "Snake", "Draw a FreeBSD \"snake\" on your screen",
	DMENU_SET_VARIABLE, "saver=snake", 0, 0		},
      { "Star",	"A \"twinkling stars\" effect",
	DMENU_SET_VARIABLE, "saver=star", 0, 0		},
      { "Timeout", "Set the screen saver timeout interval",
	DMENU_CALL, configSaverTimeout, 0, 0		},
      { "Exit", "Exit this menu (returning to previous)",
	DMENU_CANCEL, NULL, 0, 0 },
      { NULL } },
};
