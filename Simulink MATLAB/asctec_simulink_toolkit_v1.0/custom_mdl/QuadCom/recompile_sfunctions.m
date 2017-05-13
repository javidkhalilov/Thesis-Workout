CC = mex.getCompilerConfigurations('c','Selected');
arch = computer('arch');

if strcmp(CC.Manufacturer, 'Microsoft')
    if strcmp(arch, 'win32')
        fprintf('Compilation of 32-bit Binaries for ');
        fprintf('Receive S-Function...  ');
        mex 'FTDI_receive_sfun.c' 'FTDI_receive_sfun_wrapper.c' 'ftditools.c' 'ftd2xx_32.lib';
        fprintf('Send S-Function...  ');
        mex 'FTDI_send_sfun.c' 'FTDI_send_sfun_wrapper.c' 'ftditools.c' 'ftd2xx_32.lib';
        fprintf('Combined S-Function...  ');
        mex 'FTDI_sfun.c' 'FTDI_sfun_wrapper.c' 'ftditools.c' 'ftd2xx_32.lib';
        fprintf('Finished!\n');
    elseif strcmp(arch, 'win64')
        fprintf('Compilation of 64-bit Binaries for ');
        fprintf('Receive S-Function...  ');
        mex 'FTDI_receive_sfun.c' 'FTDI_receive_sfun_wrapper.c' 'ftditools.c' 'ftd2xx_64.lib';
        fprintf('Send S-Function...  ');
        mex 'FTDI_send_sfun.c' 'FTDI_send_sfun_wrapper.c' 'ftditools.c' 'ftd2xx_64.lib';
        fprintf('Combined S-Function...  ');
        mex 'FTDI_sfun.c' 'FTDI_sfun_wrapper.c' 'ftditools.c' 'ftd2xx_64.lib';
        fprintf('Finished!\n');
    else
        fprintf('Unsupported Architecture!');
    end
else
    disp('1. Install a supported compiler (e.g. Microsoft Windows SDK 7.1):');
    disp('   http://www.mathworks.de/support/compilers');
    disp('2. Use the command "mex -setup" to select your new default compiler');
end

clear arch CC;