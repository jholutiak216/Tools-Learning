import unreal
import math


#instances of unreal classes
editor_util = unreal.EditorUtilityLibrary()

#get selected assets
selected_assets = editor_util.get_selected_assets()
num_assets = len(selected_assets)
not_pow = 0

for asset in selected_assets:
    asset_name = asset.get_fname()
    asset_path = asset.get_path_name()
    
    try:
        asset_size_x = asset.blueprint_get_size_x()
        asset_size_y = asset.blueprint_get_size_y()


        #checking if both valuse are power of two
        is_x_valid = math.log(asset_size_x, 2).is_integer()
        is_y_valid = math.log(asset_size_y, 2).is_integer()

        if not is_x_valid or not is_y_valid:
            unreal.log("{} is not power of two ({}, {})".format(asset_name, asset_size_x, asset_size_y))
            unreal.log("It's path is {}".format(asset_path))
            not_pow += 1

    except Exception as err:
        unreal.log("{} is not a texture - {}".format(asset_name, err))

unreal.log("{} checked, {} textures found problematic".format(num_assets, not_pow))