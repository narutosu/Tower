--
-- DESCRIPTION
--
-- @COMPANY **
-- @AUTHOR **
-- @DATE ${date} ${time}
--

---@type BP_RoleEnemy_C
local M = UnLua.Class()

 function M:Initialize(Initializer)
	 print("Initialize")
 end

 function M:UserConstructionScript()
	 print("UserConstructionScript")
 end

function M:LuaImp_UseRoleData()
	print("LuaImp_UseRoleData")
	local RoleData = UE.URPGAssetManager.Get():ForceLoadItem(self.RoleDataID)
	if not RoleData then
		print("RoleData is nil")
		return
    end
	
	local assetBody = UE.UKismetSystemLibrary.LoadAsset_Blocking(RoleData.SkeletalMesh)
	self.Mesh:SetSkeletalMeshAsset(assetBody)

	local assetAnimClass = UE.UKismetSystemLibrary.LoadAsset_Blocking(RoleData.AnimInstance)
	self.Mesh:SetAnimInstanceClass(assetAnimClass)
end

-- function M:ReceiveBeginPlay()
-- end

-- function M:ReceiveEndPlay()
-- end

-- function M:ReceiveTick(DeltaSeconds)
-- end

-- function M:ReceiveAnyDamage(Damage, DamageType, InstigatedBy, DamageCauser)
-- end

-- function M:ReceiveActorBeginOverlap(OtherActor)
-- end

-- function M:ReceiveActorEndOverlap(OtherActor)
-- end

return M
