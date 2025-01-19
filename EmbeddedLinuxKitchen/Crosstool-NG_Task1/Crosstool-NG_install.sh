# Install dependencies
sudo apt-get install -y gcc g++ gperf bison flex texinfo help2man make libncurses5-dev python3-dev autoconf automake libtool libtool-bin gawk wget bzip2 xz-utils unzip patch libstdc++6 rsync cmake gettext git


#Clone crosstool-ng repository.
git clone https://github.com/crosstool-ng/crosstool-ng 

# Build crosstool-ng
cd crosstool-ng

# Build crosstool-ng
./bootstrap

# Configure crosstool-ng
./configure --enable-local

# Build crosstool-ng
make