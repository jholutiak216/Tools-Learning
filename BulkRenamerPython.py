import unreal

def rename_assets(search_pattern, replaced_pattern, use_case):
    system_lib = unreal.SystemLibrary()
    editor_util = unreal.EditorUtilityLibrary()
    string_lib = unreal.StringLibrary()

    #get the selected assets
    selected_assets = editor_util.get_selected_assets()
    num_assets = len(selected_assets)
    replaced = 0

    unreal.log("Selected {} assets".format(num_assets))

    #loop over the selected assets
    for asset in selected_assets:
        asset_name = system_lib.get_object_name(asset)

        if string_lib.contains(asset_name, search_pattern, use_case=use_case):
            search_case = unreal.SearchCase.CASE_SENSITIVE if use_case else unreal.SearchCase.IGNORE_CASE
            replaced_name = string_lib.replace(asset_name, search_pattern, replaced_pattern, search_case=search_case)
            editor_util.rename_asset(asset, replaced_name)

            replaced += 1
            unreal.log("Replaced {} with {}".format(asset_name, replaced_name))
        else:
            unreal.log("{} did not match the search parttern, skipped".format(asset_name))

    unreal.log("Replaced {} of {} assets". format(replaced, num_assets))

rename_assets("New", "Old", False)