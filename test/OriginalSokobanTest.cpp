
#include "RollingStoneTest.h"

namespace
{
   constexpr bool skipHeavyTests = true;
}

TEST_F(RollingStoneTest, OriginalLevel1Test)
{
	const std::string mazeStr =
R"(    #####
    #   #
    #$  #
  ###  $##
  #  $ $ #
### # ## #   ######
#   # ## #####  ..#
# $  $          ..#
##### ### #@##  ..#
    #     #########
    #######
)";

	auto path = FindPath(mazeStr);
	ASSERT_EQ(path.size(), 44);
}

TEST_F(RollingStoneTest, OriginalLevel2Test)
{
	const std::string mazeStr =
R"(############
#..  #     ###
#..  # $  $  #
#..  #$####  #
#..    @ ##  #
#..  # #  $ ##
###### ##$ $ #
  # $  $ $ $ #
  #    #     #
  ############
)";

	auto path = FindPath(mazeStr);
	ASSERT_EQ(path.size(), 76);
}

TEST_F(RollingStoneTest, OriginalLevel3Test)
{
	const std::string mazeStr =
R"(        ########
        #     @#
        # $#$ ##
        # $  $#
        ##$ $ #
######### $ # ###
#....  ## $  $  #
##...    $  $   #
#....  ##########
########
)";

	auto path = FindPath(mazeStr);
	ASSERT_EQ(path.size(), 67);
}

TEST_F(RollingStoneTest, OriginalLevel4Test)
{
	const std::string mazeStr =
R"(           ########
           #  ....#
############  ....#
#    #  $ $   ....#
# $$$#$  $ #  ....#
#  $     $ #  ....#
# $$ #$ $ $########
#  $ #     #
## #########
#    #    ##
#     $   ##
#  $$#$$  @#
#    #    ##
###########
)";

	auto path = FindPath(mazeStr);
	ASSERT_EQ(path.size(), 185);
}

TEST_F(RollingStoneTest, OriginalLevel5Test)
{
	const std::string mazeStr =
R"(        #####
        #   #####
        # #$##  #
        #     $ #
######### ###   #
#....  ## $  $###
#....    $ $$ ##
#....  ##$  $ @#
#########  $  ##
        # $ $  #
        ### ## #
          #    #
          ######
)";

   if (skipHeavyTests)
      GTEST_SKIP();

	auto path = FindPath(mazeStr);
	ASSERT_EQ(path.size(), 69);
}

TEST_F(RollingStoneTest, OriginalLevel6Test)
{
	const std::string mazeStr =
R"(######  ###
#..  # ##@##
#..  ###   #
#..     $$ #
#..  # # $ #
#..### # $ #
#### $ #$  #
   #  $# $ #
   # $  $  #
   #  ##   #
   #########
)";

	auto path = FindPath(mazeStr);
	ASSERT_EQ(path.size(), 60);
}

TEST_F(RollingStoneTest, OriginalLevel7Test)
{
	const std::string mazeStr =
R"(       #####
 #######   ##
## # @## $$ #
#    $      #
#  $  ###   #
### #####$###
# $  ### ..#
# $ $ $ ...#
#    ###...#
# $$ # #...#
#  ### #####
####
)";

	auto path = FindPath(mazeStr);
	ASSERT_EQ(path.size(), 55);
}

TEST_F(RollingStoneTest, OriginalLevel8Test)
{
	const std::string mazeStr =
R"(  ####
  #  ###########
  #    $   $ $ #
  # $# $ #  $  #
  #  $ $  #    #
### $# #  #### #
#@#$ $ $  ##   #
#    $ #$#   # #
#   $    $ $ $ #
#####  #########
  #      #
  #      #
  #......#
  #......#
  #......#
  ########
)";

	auto path = FindPath(mazeStr);
	ASSERT_EQ(path.size(), 139);
}

TEST_F(RollingStoneTest, OriginalLevel9Test)
{
	const std::string mazeStr =
R"(          #######
          #  ...#
      #####  ...#
      #      . .#
      #  ##  ...#
      ## ##  ...#
     ### ########
     # $$$ ##
 #####  $ $ #####
##   #$ $   #   #
#@ $  $    $  $ #
###### $$ $ #####
     #      #
     ########
)";

	auto path = FindPath(mazeStr);
	ASSERT_EQ(path.size(), 87);
}

TEST_F(RollingStoneTest, OriginalLevel10Test)
{
	const std::string mazeStr =
R"( ###  #############
##@####       #   #
# $$   $$  $ $ ...#
#  $$$#    $  #...#
# $   # $$ $$ #...#
###   #  $    #...#
#     # $ $ $ #...#
#    ###### ###...#
## #  #  $ $  #...#
#  ## # $$ $ $##..#
# ..# #  $      #.#
# ..# # $$$ $$$ #.#
##### #       # #.#
    # ######### #.#
    #           #.#
    ###############
)";

   if (skipHeavyTests)
      GTEST_SKIP();
	auto path = FindPath(mazeStr);
	ASSERT_EQ(path.size(), 299);
}

TEST_F(RollingStoneTest, OriginalLevel11Test)
{
	const std::string mazeStr =
R"(          ####
     #### #  #
   ### @###$ #
  ##      $  #
 ##  $ $$## ##
 #  #$##     #
 # # $ $$ # ###
 #   $ #  # $ #####
####    #  $$ #   #
#### ## $         #
#.    ###  ########
#.. ..# ####
#...#.#
#.....#
#######
)";

   if (skipHeavyTests)
      GTEST_SKIP();
	auto path = FindPath(mazeStr);
	ASSERT_EQ(path.size(), 170);
}

TEST_F(RollingStoneTest, OriginalLevel12Test)
{
	const std::string mazeStr =
R"(################
#              #
# # ######     #
# #  $ $ $ $#  #
# #   $@$   ## ##
# #  $ $ $###...#
# #   $ $  ##...#
# ###$$$ $ ##...#
#     # ## ##...#
#####   ## ##...#
    #####     ###
        #     #
        #######
)";

   if (skipHeavyTests)
      GTEST_SKIP();
	auto path = FindPath(mazeStr);
	ASSERT_EQ(path.size(), 109);
}

TEST_F(RollingStoneTest, OriginalLevel17Test)
{
	const std::string mazeStr =
R"(   ##########
   #..  #   #
   #..      #
   #..  #  ####
  #######  #  ##
  #            #
  #  #  ##  #  #
#### ##  #### ##
#  $  ##### #  #
# # $  $  # $  #
# @$  $   #   ##
#### ## #######
   #    #
   ######
)";

	auto path = FindPath(mazeStr);
	ASSERT_EQ(path.size(), 78);
}